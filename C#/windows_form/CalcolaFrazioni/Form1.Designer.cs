namespace CalcolaFrazioni
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
            NumExp1TextBox = new TextBox();
            DenExp1TextBox = new TextBox();
            label1 = new Label();
            label2 = new Label();
            DenExp2TextBox = new TextBox();
            NumExp2TextBox = new TextBox();
            label3 = new Label();
            DenResTextBox = new TextBox();
            NumResTextBox = new TextBox();
            OpTextBox = new TextBox();
            label4 = new Label();
            CalcolaBtn = new Button();
            SemplificaBtn = new Button();
            errorMessage = new Label();
            SuspendLayout();
            // 
            // NumExp1TextBox
            // 
            NumExp1TextBox.Location = new Point(76, 82);
            NumExp1TextBox.Name = "NumExp1TextBox";
            NumExp1TextBox.Size = new Size(102, 23);
            NumExp1TextBox.TabIndex = 0;
            // 
            // DenExp1TextBox
            // 
            DenExp1TextBox.Location = new Point(76, 126);
            DenExp1TextBox.Name = "DenExp1TextBox";
            DenExp1TextBox.Size = new Size(102, 23);
            DenExp1TextBox.TabIndex = 1;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(76, 108);
            label1.Name = "label1";
            label1.Size = new Size(107, 15);
            label1.TabIndex = 2;
            label1.Text = "--------------------";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(283, 108);
            label2.Name = "label2";
            label2.Size = new Size(107, 15);
            label2.TabIndex = 5;
            label2.Text = "--------------------";
            // 
            // DenExp2TextBox
            // 
            DenExp2TextBox.Location = new Point(283, 126);
            DenExp2TextBox.Name = "DenExp2TextBox";
            DenExp2TextBox.Size = new Size(102, 23);
            DenExp2TextBox.TabIndex = 4;
            // 
            // NumExp2TextBox
            // 
            NumExp2TextBox.Location = new Point(283, 82);
            NumExp2TextBox.Name = "NumExp2TextBox";
            NumExp2TextBox.Size = new Size(102, 23);
            NumExp2TextBox.TabIndex = 3;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(484, 108);
            label3.Name = "label3";
            label3.Size = new Size(107, 15);
            label3.TabIndex = 8;
            label3.Text = "--------------------";
            // 
            // DenResTextBox
            // 
            DenResTextBox.Location = new Point(484, 126);
            DenResTextBox.Name = "DenResTextBox";
            DenResTextBox.Size = new Size(102, 23);
            DenResTextBox.TabIndex = 7;
            // 
            // NumResTextBox
            // 
            NumResTextBox.Location = new Point(484, 82);
            NumResTextBox.Name = "NumResTextBox";
            NumResTextBox.Size = new Size(102, 23);
            NumResTextBox.TabIndex = 6;
            // 
            // OpTextBox
            // 
            OpTextBox.Location = new Point(211, 105);
            OpTextBox.Name = "OpTextBox";
            OpTextBox.Size = new Size(42, 23);
            OpTextBox.TabIndex = 9;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(422, 106);
            label4.Name = "label4";
            label4.Size = new Size(15, 15);
            label4.TabIndex = 10;
            label4.Text = "=";
            label4.Click += label4_Click;
            // 
            // CalcolaBtn
            // 
            CalcolaBtn.Location = new Point(76, 188);
            CalcolaBtn.Name = "CalcolaBtn";
            CalcolaBtn.Size = new Size(510, 23);
            CalcolaBtn.TabIndex = 11;
            CalcolaBtn.Text = "Calcola";
            CalcolaBtn.UseVisualStyleBackColor = true;
            CalcolaBtn.Click += CalcolaBtn_Click;
            // 
            // SemplificaBtn
            // 
            SemplificaBtn.Location = new Point(76, 232);
            SemplificaBtn.Name = "SemplificaBtn";
            SemplificaBtn.Size = new Size(510, 23);
            SemplificaBtn.TabIndex = 12;
            SemplificaBtn.Text = "Semplifica";
            SemplificaBtn.UseVisualStyleBackColor = true;
            SemplificaBtn.Click += SemplificaBtn_Click;
            // 
            // errorMessage
            // 
            errorMessage.AutoSize = true;
            errorMessage.Location = new Point(326, 287);
            errorMessage.Name = "errorMessage";
            errorMessage.Size = new Size(0, 15);
            errorMessage.TabIndex = 13;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(665, 337);
            Controls.Add(errorMessage);
            Controls.Add(SemplificaBtn);
            Controls.Add(CalcolaBtn);
            Controls.Add(label4);
            Controls.Add(OpTextBox);
            Controls.Add(label3);
            Controls.Add(DenResTextBox);
            Controls.Add(NumResTextBox);
            Controls.Add(label2);
            Controls.Add(DenExp2TextBox);
            Controls.Add(NumExp2TextBox);
            Controls.Add(label1);
            Controls.Add(DenExp1TextBox);
            Controls.Add(NumExp1TextBox);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox NumExp1TextBox;
        private TextBox DenExp1TextBox;
        private Label label1;
        private Label label2;
        private TextBox DenExp2TextBox;
        private TextBox NumExp2TextBox;
        private Label label3;
        private TextBox DenResTextBox;
        private TextBox NumResTextBox;
        private TextBox OpTextBox;
        private Label label4;
        private Button CalcolaBtn;
        private Button SemplificaBtn;
        private Label errorMessage;
    }
}
