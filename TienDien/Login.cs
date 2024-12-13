using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.StartPanel;

namespace TienDien
{
    public partial class Login : Form
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
        public Login()
        {
            InitializeComponent();
        }
        private void btnRegister_Click(object sender, EventArgs e)
        {
            Register registerForm = new Register();
            registerForm.Show();
        }
        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
        Modify modify = new Modify();
        public static string CurrentUsername { get; set; }
        private void btnLogin_Click(object sender, EventArgs e)
        {   
            string tentk = txtUsername.Text;
            string matkhau = txtPassword.Text;
            if (tentk == "admin" && matkhau == "admin")
            {
                AdminForm form= new AdminForm();
                form.ShowDialog();
            }
            else if (tentk.Trim() == "") { MessageBox.Show("Vui lòng nhập tên tài khoản!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error); }
            else if (matkhau.Trim() == "") { MessageBox.Show("Vui lòng nhập mật khẩu!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error); }
            else {
                string query = "Select * from TaiKhoan where TenTaiKhoan = '" + tentk + "' and MatKhau = '" + matkhau + "'";
                if (modify.TaiKhoans(query).Count != 0)
                {
                    CurrentUsername = tentk;
                    TienDienApp appForm = new TienDienApp();
                    appForm.ShowDialog();
                }
                else
                {
                    MessageBox.Show("Tên tài khoản hoặc mật khẩu không chính xác!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
           
        }

        private void txtPassword_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                btnLogin.PerformClick();
                e.SuppressKeyPress = true;
            }
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            QuenMatKhau quenMatKhau = new QuenMatKhau();   
            quenMatKhau.ShowDialog();
        }

        private void txtUsername_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
