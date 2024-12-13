using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TienDien
{
    internal class HoaDon
    {
        private string mahoadon;
        private string tentaikhoan;
        private float sodien;
        private int thanghoadon;
        private int trangthai;
        private float thanhtien;

        public HoaDon(string maHoaDon, string tenTaiKhoan, float soDien, int thangHoaDon,int trangThai, float thanhTien)
        {
            mahoadon = maHoaDon;
            tentaikhoan = tenTaiKhoan;
            sodien = soDien;
            thanghoadon = thangHoaDon;
            trangthai = trangThai;
            thanhtien = thanhTien;
        }
        public string MaHoaDon { get => mahoadon; set => mahoadon = value; }
        public string TenTaiKhoan { get => tentaikhoan; set => tentaikhoan = value; }
        public float SoDien { get => sodien; set => sodien = value; }
        public int ThangHoaDon { get => thanghoadon; set => thanghoadon = value; }
        public int TrangThai { get => trangthai; set => trangthai = value; }
        public float ThanhTien { get => thanhtien; set => thanhtien = value; }
    }

}

