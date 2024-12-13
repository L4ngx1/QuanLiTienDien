using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TienDien
{
    internal class KhachHang
    {
        private string maKH;
        private string hoTen;
        private string diachi;
        private string sdt;
        private double elecUsage;
        public KhachHang(string maKH, string hoTen, string diachi, string sdt, double elecUsage)
        {
            this.maKH = maKH;
            this.hoTen = hoTen;
            this.diachi = diachi;
            this.sdt = sdt;
            this.elecUsage = elecUsage;
        }
        public string MaKH { get => maKH; set => maKH = value; }
        public string HoTen { get => hoTen; set => hoTen = value; }
        public string DiaChi { get => diachi; set => diachi = value; }
        public string SDT { get => sdt; set => sdt = value; }
        public double ElecUsage { get => elecUsage; set => elecUsage = value; }

        public double CalculateBill()
        {
            double rate = 0;
            if (ElecUsage <= 50)
                rate = 1000;
            else if (ElecUsage <= 100)
                rate = 1500;
            else
                rate = 2000;
            return ElecUsage * rate;
        }
    }
}
