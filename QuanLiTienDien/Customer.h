#pragma once

using namespace System;

namespace QuanLiTienDien {

    public ref class Customer
    {
    public:
        String^ ID;
        String^ Name;
        String^ Address;
        String^ PhoneNumber;
        double ElecUsage;  // Double value for electricity usage

        // Constructor accepting all fields
        Customer(String^ id, String^ name, String^ address, String^ phoneNumber, double elecUsage)
        {
            this->ID = id;
            this->Name = name;
            this->Address = address;
            this->PhoneNumber = phoneNumber;
            this->ElecUsage = elecUsage; // Correct assignment of double
        }
        String^ GetElecUsageString() {
            return ElecUsage.ToString("F2");  // Format to 2 decimal places
        }
    };
}
