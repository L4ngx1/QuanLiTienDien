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
        double ElecUsage;
        Customer(String^ id, String^ name, String^ address, String^ phoneNumber, double elecUsage)
        {
            this->ID = id;
            this->Name = name;
            this->Address = address;
            this->PhoneNumber = phoneNumber;
            this->ElecUsage = elecUsage;
        }
        String^ ElectricityUsage() {
            return ElecUsage.ToString("F2");
        }
        double CalculateBill(){
            const double ratePerKWh = 1000;
            return ElecUsage * ratePerKWh;
        }
    };
}
