using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TienDien
{
    public partial class Register : Form
    {
        //Di chuyen Form khong can border
        public Point mouseLocation;
        private void Mouse_Down(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                mouseLocation = new Point(e.X, e.Y);
            }
        }
        private void Mouse_Move(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.Location = new Point(this.Location.X + (e.X - mouseLocation.X), this.Location.Y + (e.Y - mouseLocation.Y));
            }
        }
        public Register()
        {
            InitializeComponent();
        }
        Modify modify = new Modify();
        private void btnRegister_Click(object sender, EventArgs e)
        {
            string xacnhanMK=txtXacNhanMK.Text;
            string tentk=txtUsername.Text;
            string matkhau = txtPassword.Text;
            string email = txtEmail.Text;
            if (email.Trim() == "") { MessageBox.Show("Vui lòng nhập Email!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error); }
            else if (tentk.Trim() == "") { MessageBox.Show("Vui lòng nhập tên tài khoản!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error); }
            else if (matkhau.Trim() == "") { MessageBox.Show("Vui lòng nhập mật khẩu!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error); }
            else if (xacnhanMK != matkhau) { MessageBox.Show("Mật khẩu xác nhận không trùng!","Error", MessageBoxButtons.OK, MessageBoxIcon.Error); }
            else if (modify.TaiKhoans("Select * from TaiKhoan where Email = '" + email + "'").Count() != 0)
            {

                MessageBox.Show("Email này đã được đăng ký!", "Register", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }
            else
            {
                try
                {
                    string query = "Insert into TaiKhoan values ('" + tentk + "','" + matkhau + "','" + email + "')";
                    modify.Command(query);
                    MessageBox.Show("Đăng ký thành công!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    this.Close();
                }
                catch
                {
                    MessageBox.Show("Tên tài khoản này đã được đăng ký!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }
        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void txtXacNhanMK_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                btnRegister.PerformClick();
                e.SuppressKeyPress = true;
            }
        }
    }
}
