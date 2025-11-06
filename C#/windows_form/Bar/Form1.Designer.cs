namespace Bar
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
            groupBoxNomeCliente = new GroupBox();
            radioButtonAranciata = new RadioButton();
            radioButtonCappuccino = new RadioButton();
            radioButtonCaffe = new RadioButton();
            label2 = new Label();
            comboBox1 = new ComboBox();
            label1 = new Label();
            groupBox2 = new GroupBox();
            textBox1 = new TextBox();
            buttonOrdina = new Button();
            button1 = new Button();
            groupBoxNomeCliente.SuspendLayout();
            groupBox2.SuspendLayout();
            SuspendLayout();
            // 
            // groupBoxNomeCliente
            // 
            groupBoxNomeCliente.Controls.Add(radioButtonAranciata);
            groupBoxNomeCliente.Controls.Add(radioButtonCappuccino);
            groupBoxNomeCliente.Controls.Add(radioButtonCaffe);
            groupBoxNomeCliente.Controls.Add(label2);
            groupBoxNomeCliente.Controls.Add(comboBox1);
            groupBoxNomeCliente.Controls.Add(label1);
            groupBoxNomeCliente.Location = new Point(15, 13);
            groupBoxNomeCliente.Name = "groupBoxNomeCliente";
            groupBoxNomeCliente.Size = new Size(318, 144);
            groupBoxNomeCliente.TabIndex = 0;
            groupBoxNomeCliente.TabStop = false;
            groupBoxNomeCliente.Text = "Banco del bar";
            // 
            // radioButtonAranciata
            // 
            radioButtonAranciata.AutoSize = true;
            radioButtonAranciata.Location = new Point(210, 100);
            radioButtonAranciata.Name = "radioButtonAranciata";
            radioButtonAranciata.Size = new Size(75, 19);
            radioButtonAranciata.TabIndex = 5;
            radioButtonAranciata.TabStop = true;
            radioButtonAranciata.Text = "Aranciata";
            radioButtonAranciata.UseVisualStyleBackColor = true;
            radioButtonAranciata.CheckedChanged += radioButtonAranciata_CheckedChanged;
            // 
            // radioButtonCappuccino
            // 
            radioButtonCappuccino.AutoSize = true;
            radioButtonCappuccino.Location = new Point(104, 100);
            radioButtonCappuccino.Name = "radioButtonCappuccino";
            radioButtonCappuccino.Size = new Size(89, 19);
            radioButtonCappuccino.TabIndex = 4;
            radioButtonCappuccino.TabStop = true;
            radioButtonCappuccino.Text = "Cappuccino";
            radioButtonCappuccino.UseVisualStyleBackColor = true;
            radioButtonCappuccino.CheckedChanged += radioButtonCappuccino_CheckedChanged;
            // 
            // radioButtonCaffe
            // 
            radioButtonCaffe.AutoSize = true;
            radioButtonCaffe.Location = new Point(22, 100);
            radioButtonCaffe.Name = "radioButtonCaffe";
            radioButtonCaffe.Size = new Size(53, 19);
            radioButtonCaffe.TabIndex = 3;
            radioButtonCaffe.TabStop = true;
            radioButtonCaffe.Text = "Caffè";
            radioButtonCaffe.UseVisualStyleBackColor = true;
            radioButtonCaffe.CheckedChanged += radioButtonCaffe_CheckedChanged;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(36, 72);
            label2.Name = "label2";
            label2.Size = new Size(217, 15);
            label2.TabIndex = 2;
            label2.Text = "---------- Cosa vuoi ordinare? ----------";
            // 
            // comboBox1
            // 
            comboBox1.FormattingEnabled = true;
            comboBox1.Location = new Point(124, 31);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(175, 23);
            comboBox1.TabIndex = 1;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(15, 34);
            label1.Name = "label1";
            label1.Size = new Size(93, 15);
            label1.TabIndex = 0;
            label1.Text = "Come ti chiami?";
            // 
            // groupBox2
            // 
            groupBox2.Controls.Add(textBox1);
            groupBox2.Location = new Point(15, 248);
            groupBox2.Name = "groupBox2";
            groupBox2.Size = new Size(318, 175);
            groupBox2.TabIndex = 1;
            groupBox2.TabStop = false;
            groupBox2.Text = "Scontrino";
            // 
            // textBox1
            // 
            textBox1.Location = new Point(15, 22);
            textBox1.Multiline = true;
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(290, 129);
            textBox1.TabIndex = 0;
            // 
            // buttonOrdina
            // 
            buttonOrdina.Location = new Point(24, 163);
            buttonOrdina.Name = "buttonOrdina";
            buttonOrdina.Size = new Size(309, 33);
            buttonOrdina.TabIndex = 2;
            buttonOrdina.Text = "Ordina";
            buttonOrdina.UseVisualStyleBackColor = true;
            buttonOrdina.Click += buttonOrdina_Click;
            // 
            // button1
            // 
            button1.Location = new Point(24, 202);
            button1.Name = "button1";
            button1.Size = new Size(309, 33);
            button1.TabIndex = 3;
            button1.Text = "Calcola conto";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(345, 448);
            Controls.Add(button1);
            Controls.Add(buttonOrdina);
            Controls.Add(groupBox2);
            Controls.Add(groupBoxNomeCliente);
            Name = "Form1";
            Text = "Bar ISII";
            groupBoxNomeCliente.ResumeLayout(false);
            groupBoxNomeCliente.PerformLayout();
            groupBox2.ResumeLayout(false);
            groupBox2.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private GroupBox groupBoxNomeCliente;
        private ComboBox comboBox1;
        private Label label1;
        private GroupBox groupBox2;
        private RadioButton radioButtonAranciata;
        private RadioButton radioButtonCappuccino;
        private RadioButton radioButtonCaffe;
        private Label label2;
        private TextBox textBox1;
        private Button buttonOrdina;
        private Button button1;
    }
}
