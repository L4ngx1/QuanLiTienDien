using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Microsoft.Reporting.WinForms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.StartPanel;
using static TienDien.Login;

namespace TienDien
{
    public partial class HoaDonForm : Form
    {
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
        public HoaDonForm()
        {
            InitializeComponent();
        }
        private void HoaDonForm_Load(object sender, EventArgs e)
        {
            Modify modify = new Modify();
            string tentk = Login.CurrentUsername;
            reportViewer1.LocalReport.ReportEmbeddedResource = "TienDien.ReportHoaDon.rdlc";
            ReportDataSource reportDataSource = new ReportDataSource();
            reportDataSource.Name = "DataSet1";
            reportDataSource.Value = modify.getHoaDon(tentk);
            reportViewer1.LocalReport.DataSources.Add(reportDataSource);
            this.reportViewer1.RefreshReport();
        }
        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void reportViewer1_Load(object sender, EventArgs e)
        {

        }
    }
}
