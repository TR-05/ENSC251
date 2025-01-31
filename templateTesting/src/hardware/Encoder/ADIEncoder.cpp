#include "hardware/Encoder/ADIEncoder.hpp"
#include "hardware/Port.hpp"
#include <cmath>
#include <limits.h>
#include <mutex>

namespace lemlib {
ADIEncoder::ADIEncoder(pros::adi::Encoder encoder)
    : m_encoder(encoder) {}

ADIEncoder::ADIEncoder(ADIPair ports, bool reversed)
    : m_encoder(pros::adi::Encoder(ports.first(), ports.second(), reversed)) {}

ADIEncoder::ADIEncoder(SmartPort expanderPort, ADIPair ports, bool reversed)
    : m_encoder({expanderPort, ports.first(), ports.second()}, reversed) {}

ADIEncoder::ADIEncoder(const ADIEncoder& other)
    : m_encoder(other.m_encoder),
      m_offset(other.m_offset) {}

int32_t ADIEncoder::isConnected() const {
    // it's not possible to check if the ADIEncoder is connected, so we just return 1 to indicate that it is
    // we do run a simple test however to check if the ports are valid
    if (m_encoder.get_value() == INT_MAX) {
        errno = ENODEV;
        return INT_MAX;
    }
    // return 1 to indicate that the encoder is "connected"
    return 1;
}

Angle ADIEncoder::getAngle() const {
    std::unique_lock lock(m_mutex);
    const int raw = m_encoder.get_value();
    // check for errors
    if (raw == INT_MAX) {
        errno = ENODEV;
        return Angle(INFINITY);
    }
    // return the angle
    return from_stDeg(raw) + m_offset;
}

int32_t ADIEncoder::setAngle(Angle angle) {
    std::unique_lock lock(m_mutex);
    // the Vex SDK does not support setting the relative angle of an ADI encoder to a specific value
    // but we can overcome this limitation by resetting the relative angle to zero and saving an offset
    m_offset = angle;
    const int result = m_encoder.reset();
    // check for errors
    if (result == INT_MAX) {
        errno = ENODEV;
        return INT_MAX;
    }
    // return 0 on success
    return 0;
}
} // namespace lemlib