namespace Sveglia
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
            components = new System.ComponentModel.Container();
            groupBox1 = new GroupBox();
            label7 = new Label();
            label6 = new Label();
            labelTimerSecondi = new Label();
            labelTimerMinuti = new Label();
            labelTimerOre = new Label();
            textBoxMinuti = new TextBox();
            label1 = new Label();
            label2 = new Label();
            textBoxOre = new TextBox();
            label3 = new Label();
            textBoxSecondi = new TextBox();
            btnStart = new Button();
            timer = new System.Windows.Forms.Timer(components);
            groupBox1.SuspendLayout();
            SuspendLayout();
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(label7);
            groupBox1.Controls.Add(label6);
            groupBox1.Controls.Add(labelTimerSecondi);
            groupBox1.Controls.Add(labelTimerMinuti);
            groupBox1.Controls.Add(labelTimerOre);
            groupBox1.Location = new Point(32, 26);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(288, 140);
            groupBox1.TabIndex = 0;
            groupBox1.TabStop = false;
            groupBox1.Text = "Timer";
            groupBox1.Enter += groupBox1_Enter;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Font = new Font("Segoe UI", 19F);
            label7.Location = new Point(173, 52);
            label7.Name = "label7";
            label7.Size = new Size(21, 36);
            label7.TabIndex = 4;
            label7.Text = ":";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("Segoe UI", 19F);
            label6.Location = new Point(100, 52);
            label6.Name = "label6";
            label6.Size = new Size(21, 36);
            label6.TabIndex = 3;
            label6.Text = ":";
            // 
            // labelTimerSecondi
            // 
            labelTimerSecondi.AutoSize = true;
            labelTimerSecondi.Font = new Font("Segoe UI", 18F);
            labelTimerSecondi.Location = new Point(200, 54);
            labelTimerSecondi.Name = "labelTimerSecondi";
            labelTimerSecondi.Size = new Size(40, 32);
            labelTimerSecondi.TabIndex = 2;
            labelTimerSecondi.Text = "00";
            // 
            // labelTimerMinuti
            // 
            labelTimerMinuti.AutoSize = true;
            labelTimerMinuti.Font = new Font("Segoe UI", 18F);
            labelTimerMinuti.Location = new Point(127, 54);
            labelTimerMinuti.Name = "labelTimerMinuti";
            labelTimerMinuti.Size = new Size(40, 32);
            labelTimerMinuti.TabIndex = 1;
            labelTimerMinuti.Text = "00";
            labelTimerMinuti.Click += label4_Click;
            // 
            // labelTimerOre
            // 
            labelTimerOre.AutoSize = true;
            labelTimerOre.Font = new Font("Segoe UI", 18F);
            labelTimerOre.Location = new Point(54, 54);
            labelTimerOre.Name = "labelTimerOre";
            labelTimerOre.Size = new Size(40, 32);
            labelTimerOre.TabIndex = 0;
            labelTimerOre.Text = "00";
            // 
            // textBoxMinuti
            // 
            textBoxMinuti.Location = new Point(117, 237);
            textBoxMinuti.Name = "textBoxMinuti";
            textBoxMinuti.Size = new Size(155, 23);
            textBoxMinuti.TabIndex = 1;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(64, 240);
            label1.Name = "label1";
            label1.Size = new Size(42, 15);
            label1.TabIndex = 2;
            label1.Text = "Minuti";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(64, 211);
            label2.Name = "label2";
            label2.Size = new Size(26, 15);
            label2.TabIndex = 4;
            label2.Text = "Ore";
            // 
            // textBoxOre
            // 
            textBoxOre.Location = new Point(117, 208);
            textBoxOre.Name = "textBoxOre";
            textBoxOre.Size = new Size(155, 23);
            textBoxOre.TabIndex = 3;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(64, 269);
            label3.Name = "label3";
            label3.Size = new Size(49, 15);
            label3.TabIndex = 6;
            label3.Text = "Secondi";
            label3.Click += label3_Click;
            // 
            // textBoxSecondi
            // 
            textBoxSecondi.Location = new Point(117, 266);
            textBoxSecondi.Name = "textBoxSecondi";
            textBoxSecondi.Size = new Size(155, 23);
            textBoxSecondi.TabIndex = 5;
            // 
            // btnStart
            // 
            btnStart.Location = new Point(32, 323);
            btnStart.Name = "btnStart";
            btnStart.Size = new Size(288, 23);
            btnStart.TabIndex = 7;
            btnStart.Text = "Start";
            btnStart.UseVisualStyleBackColor = true;
            btnStart.Click += btnStart_Click;
            // 
            // timer
            // 
            timer.Interval = 1000;
            timer.Tick += timer1_Tick;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(363, 388);
            Controls.Add(btnStart);
            Controls.Add(label3);
            Controls.Add(textBoxSecondi);
            Controls.Add(label2);
            Controls.Add(textBoxOre);
            Controls.Add(label1);
            Controls.Add(textBoxMinuti);
            Controls.Add(groupBox1);
            Name = "Form1";
            Text = "Sveglia";
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private GroupBox groupBox1;
        private TextBox textBoxMinuti;
        private Label label1;
        private Label label2;
        private TextBox textBoxOre;
        private Label label3;
        private TextBox textBoxSecondi;
        private Label label6;
        private Label labelTimerSecondi;
        private Label labelTimerMinuti;
        private Label labelTimerOre;
        private Label label7;
        private Button btnStart;
        private System.Windows.Forms.Timer timer;
    }
}
