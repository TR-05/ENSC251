/**
 * @file ShippingContainer.h
 * @author Trevor Ruttan
 * @Date 10/3/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Trevor Ruttan ____ _____10/3/2024______________
//
// ____ 301580889 ______
//

#include <string>

#include <vector>

class ShippingContainer {
  protected: 
  int containerID;
  public:
    // Constructor taking in yearModel and make
    ShippingContainer();
    ~ShippingContainer();

    int getContainerID();
    void setContainerID(int containerID);
    virtual std::string getManifest();
};


class ManualShippingContainer : public ShippingContainer {
  protected:
   std::string manifest;
  public:
    // Constructor taking in yearModel and make
    ManualShippingContainer();
    ~ManualShippingContainer();

    void setManifest(std::string manifest);
    std::string getManifest() override;
};

class RFIDShippingContainer : public ShippingContainer {
  protected:
   // Vector to store the items in the container, as well as the number of each item, using the same index
   std::vector<std::string> items;
   std::vector<int> numItems;
  public:
    // Constructor taking in yearModel and make
    RFIDShippingContainer();
    ~RFIDShippingContainer();

    void add(std::string item);
    std::string getManifest() override;
};