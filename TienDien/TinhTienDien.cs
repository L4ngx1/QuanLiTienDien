using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;
using System.Data.SqlClient;
using Microsoft.Reporting.WinForms;
using static System.Net.Mime.MediaTypeNames;

namespace TienDien
{
    public partial class TinhTienDien : UserControl
    {
        public TinhTienDien()
        {
            InitializeComponent();
        }
        private void TinhTienDien_Load(object sender, EventArgs e)
        {
            Modify modify = new Modify();
            try
            {
                dataGridView1.DataSource = modify.getHoaDon(txtTenTK.Text);

            }
            catch (Exception ex)
            {

                MessageBox.Show("Lỗi!!" + ex.Message, "Lỗi!!");
            }
        }

        private void btnLoad_Click(object sender, EventArgs e)
        {
            Modify modify = new Modify();
            try
            {
                string query = "Update HoaDon Set ThanhTien =  SoDien * 1000  where TenTaiKhoan = '" + txtTenTK.Text + "'";
                modify.Command(query);
                dataGridView1.DataSource = modify.getHoaDon(txtTenTK.Text);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Lỗi!!" + ex.Message, "Lỗi!!");
            }
        }

        private void btnThanhToan_Click(object sender, EventArgs e)
        {
            Modify modify = new Modify();
            string query = "Update HoaDon Set TrangThaiThanhToan = 1 where TenTaiKhoan = '"+txtTenTK.Text+"'";
            try
            {
                modify.Command(query);
                MessageBox.Show("Thanh toán thành công!!");
                TinhTienDien_Load(sender, e);
            }
            catch(Exception ex)
            {
                MessageBox.Show("Lỗi thanh toán!"+ex);
            }
        }

        private void txtMaKH_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                btnLoad.PerformClick();
                e.SuppressKeyPress = true;
            }
        }

        private void btnXuatHoaDon_Click(object sender, EventArgs e)
        {
            HoaDonForm hoaDonForm = new HoaDonForm();
            hoaDonForm.ShowDialog();
        }

    }
}
