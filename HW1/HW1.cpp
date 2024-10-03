/**
 * @file lab2.cpp
 * @author Trevor Ruttan
 * @Date 9/24/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Trevor Ruttan ____ _____9/24/2024______________
//
// ____ 301580889 ______
//

#include <iostream>
#include "ShippingContainer.h"

int main() {
    // Create an array of pointers to ShippingContainer objects
    ShippingContainer* containers[6];

    // Dynamically allocate memory for each object
    containers[0] = new ManualShippingContainer();
    containers[1] = new ManualShippingContainer();
    containers[2] = new ManualShippingContainer();
    containers[3] = new RFIDShippingContainer();
    containers[4] = new RFIDShippingContainer();
    containers[5] = new RFIDShippingContainer();

    // Set container IDs
    containers[0]->setContainerID(27);
    containers[1]->setContainerID(28);
    containers[2]->setContainerID(29);
    containers[3]->setContainerID(35);
    containers[4]->setContainerID(36);
    containers[5]->setContainerID(37);

    // Print container IDs
    for (int i = 0; i < 6; ++i) {
        std::cout << "Container " << i << " ID: " << containers[i]->getContainerID() << std::endl;
    }

    // Set manifests and add items
    dynamic_cast<ManualShippingContainer*>(containers[0])->setManifest("This is a manifest for container 0");
    dynamic_cast<ManualShippingContainer*>(containers[1])->setManifest("This is a manifest for container 1");
    dynamic_cast<ManualShippingContainer*>(containers[2])->setManifest("This is a manifest for container 2");

    dynamic_cast<RFIDShippingContainer*>(containers[3])->add("crate of pears");
    dynamic_cast<RFIDShippingContainer*>(containers[3])->add("crate of apples");
    dynamic_cast<RFIDShippingContainer*>(containers[3])->add("crate of pears");

    dynamic_cast<RFIDShippingContainer*>(containers[4])->add("crate of bananas");
    dynamic_cast<RFIDShippingContainer*>(containers[4])->add("crate of oranges");

    dynamic_cast<RFIDShippingContainer*>(containers[5])->add("crate of grapes");

    // Print manifests
    for (int i = 0; i < 6; ++i) {
        std::cout << "Container " << i << " Manifest: " << containers[i]->getManifest() << std::endl;
    }

    return 0;
}