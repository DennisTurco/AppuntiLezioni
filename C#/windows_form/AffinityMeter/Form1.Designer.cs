namespace AffinityMeter
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            groupBox1 = new GroupBox();
            groupBox4 = new GroupBox();
            listBoxLuiStudy = new ListBox();
            groupBox5 = new GroupBox();
            checkBoxLuiViaggi = new CheckBox();
            checkBoxLuiSport = new CheckBox();
            groupBox2 = new GroupBox();
            comboBoxLuiAge = new ComboBox();
            buttonCalculateAffinity = new Button();
            groupBox3 = new GroupBox();
            label1 = new Label();
            progressBar = new ProgressBar();
            groupBox6 = new GroupBox();
            groupBox7 = new GroupBox();
            checkBoxLeiViaggi = new CheckBox();
            checkBoxLeiSport = new CheckBox();
            groupBox8 = new GroupBox();
            listBoxLeiStudy = new ListBox();
            groupBox9 = new GroupBox();
            comboBoxLeiAge = new ComboBox();
            groupBox1.SuspendLayout();
            groupBox4.SuspendLayout();
            groupBox5.SuspendLayout();
            groupBox2.SuspendLayout();
            groupBox3.SuspendLayout();
            groupBox6.SuspendLayout();
            groupBox7.SuspendLayout();
            groupBox8.SuspendLayout();
            groupBox9.SuspendLayout();
            SuspendLayout();
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(groupBox4);
            groupBox1.Controls.Add(groupBox5);
            groupBox1.Controls.Add(groupBox2);
            groupBox1.Location = new Point(12, 20);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(216, 325);
            groupBox1.TabIndex = 0;
            groupBox1.TabStop = false;
            groupBox1.Text = "Lui";
            // 
            // groupBox4
            // 
            groupBox4.Controls.Add(listBoxLuiStudy);
            groupBox4.Location = new Point(15, 99);
            groupBox4.Name = "groupBox4";
            groupBox4.Size = new Size(186, 104);
            groupBox4.TabIndex = 4;
            groupBox4.TabStop = false;
            groupBox4.Text = "Titolo di studio";
            // 
            // listBoxLuiStudy
            // 
            listBoxLuiStudy.FormattingEnabled = true;
            listBoxLuiStudy.ItemHeight = 15;
            listBoxLuiStudy.Location = new Point(6, 22);
            listBoxLuiStudy.Name = "listBoxLuiStudy";
            listBoxLuiStudy.Size = new Size(161, 64);
            listBoxLuiStudy.TabIndex = 0;
            listBoxLuiStudy.SelectedIndexChanged += listBoxLuiStudy_SelectedIndexChanged;
            // 
            // groupBox5
            // 
            groupBox5.Controls.Add(checkBoxLuiViaggi);
            groupBox5.Controls.Add(checkBoxLuiSport);
            groupBox5.Location = new Point(15, 218);
            groupBox5.Name = "groupBox5";
            groupBox5.Size = new Size(186, 77);
            groupBox5.TabIndex = 4;
            groupBox5.TabStop = false;
            groupBox5.Text = "Interessi";
            // 
            // checkBoxLuiViaggi
            // 
            checkBoxLuiViaggi.AutoSize = true;
            checkBoxLuiViaggi.Location = new Point(78, 35);
            checkBoxLuiViaggi.Name = "checkBoxLuiViaggi";
            checkBoxLuiViaggi.Size = new Size(59, 19);
            checkBoxLuiViaggi.TabIndex = 1;
            checkBoxLuiViaggi.Text = "Viaggi";
            checkBoxLuiViaggi.UseVisualStyleBackColor = true;
            // 
            // checkBoxLuiSport
            // 
            checkBoxLuiSport.AutoSize = true;
            checkBoxLuiSport.Location = new Point(10, 36);
            checkBoxLuiSport.Name = "checkBoxLuiSport";
            checkBoxLuiSport.Size = new Size(54, 19);
            checkBoxLuiSport.TabIndex = 0;
            checkBoxLuiSport.Text = "Sport";
            checkBoxLuiSport.UseVisualStyleBackColor = true;
            // 
            // groupBox2
            // 
            groupBox2.Controls.Add(comboBoxLuiAge);
            groupBox2.Location = new Point(15, 31);
            groupBox2.Name = "groupBox2";
            groupBox2.Size = new Size(186, 62);
            groupBox2.TabIndex = 2;
            groupBox2.TabStop = false;
            groupBox2.Text = "Età";
            // 
            // comboBoxLuiAge
            // 
            comboBoxLuiAge.FormattingEnabled = true;
            comboBoxLuiAge.Location = new Point(6, 22);
            comboBoxLuiAge.Name = "comboBoxLuiAge";
            comboBoxLuiAge.Size = new Size(156, 23);
            comboBoxLuiAge.TabIndex = 0;
            comboBoxLuiAge.SelectedIndexChanged += comboBoxLuiAge_SelectedIndexChanged;
            // 
            // buttonCalculateAffinity
            // 
            buttonCalculateAffinity.Location = new Point(12, 375);
            buttonCalculateAffinity.Name = "buttonCalculateAffinity";
            buttonCalculateAffinity.Size = new Size(456, 49);
            buttonCalculateAffinity.TabIndex = 2;
            buttonCalculateAffinity.Text = "Valuta Affinità";
            buttonCalculateAffinity.UseVisualStyleBackColor = true;
            buttonCalculateAffinity.Click += buttonCalculateAffinity_Click;
            // 
            // groupBox3
            // 
            groupBox3.Controls.Add(label1);
            groupBox3.Controls.Add(progressBar);
            groupBox3.Location = new Point(18, 447);
            groupBox3.Name = "groupBox3";
            groupBox3.Size = new Size(450, 96);
            groupBox3.TabIndex = 3;
            groupBox3.TabStop = false;
            groupBox3.Text = "Livello di affinità";
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 20F);
            label1.Location = new Point(36, 22);
            label1.Name = "label1";
            label1.Size = new Size(54, 37);
            label1.TabIndex = 1;
            label1.Text = "0%";
            // 
            // progressBar
            // 
            progressBar.Location = new Point(112, 22);
            progressBar.Name = "progressBar";
            progressBar.Size = new Size(323, 53);
            progressBar.TabIndex = 0;
            // 
            // groupBox6
            // 
            groupBox6.Controls.Add(groupBox7);
            groupBox6.Controls.Add(groupBox8);
            groupBox6.Controls.Add(groupBox9);
            groupBox6.Location = new Point(252, 20);
            groupBox6.Name = "groupBox6";
            groupBox6.Size = new Size(216, 325);
            groupBox6.TabIndex = 5;
            groupBox6.TabStop = false;
            groupBox6.Text = "Lei";
            // 
            // groupBox7
            // 
            groupBox7.Controls.Add(checkBoxLeiViaggi);
            groupBox7.Controls.Add(checkBoxLeiSport);
            groupBox7.Location = new Point(15, 218);
            groupBox7.Name = "groupBox7";
            groupBox7.Size = new Size(186, 77);
            groupBox7.TabIndex = 4;
            groupBox7.TabStop = false;
            groupBox7.Text = "Interessi";
            // 
            // checkBoxLeiViaggi
            // 
            checkBoxLeiViaggi.AutoSize = true;
            checkBoxLeiViaggi.Location = new Point(78, 35);
            checkBoxLeiViaggi.Name = "checkBoxLeiViaggi";
            checkBoxLeiViaggi.Size = new Size(59, 19);
            checkBoxLeiViaggi.TabIndex = 1;
            checkBoxLeiViaggi.Text = "Viaggi";
            checkBoxLeiViaggi.UseVisualStyleBackColor = true;
            // 
            // checkBoxLeiSport
            // 
            checkBoxLeiSport.AutoSize = true;
            checkBoxLeiSport.Location = new Point(10, 36);
            checkBoxLeiSport.Name = "checkBoxLeiSport";
            checkBoxLeiSport.Size = new Size(54, 19);
            checkBoxLeiSport.TabIndex = 0;
            checkBoxLeiSport.Text = "Sport";
            checkBoxLeiSport.UseVisualStyleBackColor = true;
            // 
            // groupBox8
            // 
            groupBox8.Controls.Add(listBoxLeiStudy);
            groupBox8.Location = new Point(15, 99);
            groupBox8.Name = "groupBox8";
            groupBox8.Size = new Size(186, 104);
            groupBox8.TabIndex = 3;
            groupBox8.TabStop = false;
            groupBox8.Text = "Titolo di studio";
            // 
            // listBoxLeiStudy
            // 
            listBoxLeiStudy.FormattingEnabled = true;
            listBoxLeiStudy.ItemHeight = 15;
            listBoxLeiStudy.Location = new Point(10, 22);
            listBoxLeiStudy.Name = "listBoxLeiStudy";
            listBoxLeiStudy.Size = new Size(161, 64);
            listBoxLeiStudy.TabIndex = 1;
            // 
            // groupBox9
            // 
            groupBox9.Controls.Add(comboBoxLeiAge);
            groupBox9.Location = new Point(15, 31);
            groupBox9.Name = "groupBox9";
            groupBox9.Size = new Size(186, 62);
            groupBox9.TabIndex = 2;
            groupBox9.TabStop = false;
            groupBox9.Text = "Età";
            // 
            // comboBoxLeiAge
            // 
            comboBoxLeiAge.FormattingEnabled = true;
            comboBoxLeiAge.Location = new Point(6, 22);
            comboBoxLeiAge.Name = "comboBoxLeiAge";
            comboBoxLeiAge.Size = new Size(156, 23);
            comboBoxLeiAge.TabIndex = 0;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(497, 551);
            Controls.Add(groupBox6);
            Controls.Add(groupBox3);
            Controls.Add(buttonCalculateAffinity);
            Controls.Add(groupBox1);
            Name = "Form1";
            Text = "AffinityMeter";
            groupBox1.ResumeLayout(false);
            groupBox4.ResumeLayout(false);
            groupBox5.ResumeLayout(false);
            groupBox5.PerformLayout();
            groupBox2.ResumeLayout(false);
            groupBox3.ResumeLayout(false);
            groupBox3.PerformLayout();
            groupBox6.ResumeLayout(false);
            groupBox7.ResumeLayout(false);
            groupBox7.PerformLayout();
            groupBox8.ResumeLayout(false);
            groupBox9.ResumeLayout(false);
            ResumeLayout(false);
        }

        #endregion

        private GroupBox groupBox1;
        private Button buttonCalculateAffinity;
        private GroupBox groupBox3;
        private Label label3;
        private Label label1;
        private ProgressBar progressBar;
        private GroupBox groupBox2;
        private ComboBox comboBoxLuiAge;
        private GroupBox groupBox5;
        private CheckBox checkBoxLuiViaggi;
        private CheckBox checkBoxLuiSport;
        private GroupBox groupBox6;
        private GroupBox groupBox7;
        private CheckBox checkBoxLeiViaggi;
        private CheckBox checkBoxLeiSport;
        private GroupBox groupBox8;
        private GroupBox groupBox9;
        private ComboBox comboBoxLeiAge;
        private GroupBox groupBox4;
        private ListBox listBoxLuiStudy;
        private ListBox listBoxLeiStudy;
    }
}
