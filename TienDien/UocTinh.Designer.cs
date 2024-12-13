namespace TienDien
{
    partial class UocTinh
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.lblUocTinh = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // lblUocTinh
            // 
            this.lblUocTinh.AutoSize = true;
            this.lblUocTinh.Font = new System.Drawing.Font("Segoe UI Semilight", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblUocTinh.Location = new System.Drawing.Point(3, 0);
            this.lblUocTinh.Name = "lblUocTinh";
            this.lblUocTinh.Size = new System.Drawing.Size(176, 25);
            this.lblUocTinh.TabIndex = 1;
            this.lblUocTinh.Text = "Ước Tính Điện Năng";
            // 
            // UocTinh
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.lblUocTinh);
            this.Name = "UocTinh";
            this.Size = new System.Drawing.Size(880, 672);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblUocTinh;
    }
}
