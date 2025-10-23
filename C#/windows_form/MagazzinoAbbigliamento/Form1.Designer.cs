namespace MagazzinoAbbigliamento
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
            labelTipo = new Label();
            labelTaglia = new Label();
            groupBox1 = new GroupBox();
            buttonCancella = new Button();
            comboBoxTaglia = new ComboBox();
            comboBoxTipo = new ComboBox();
            buttonInserisci = new Button();
            groupBox2 = new GroupBox();
            buttonCerca = new Button();
            textBoxElenco = new TextBox();
            label1 = new Label();
            groupBox1.SuspendLayout();
            groupBox2.SuspendLayout();
            SuspendLayout();
            // 
            // labelTipo
            // 
            labelTipo.AutoSize = true;
            labelTipo.Location = new Point(39, 41);
            labelTipo.Name = "labelTipo";
            labelTipo.Size = new Size(30, 15);
            labelTipo.TabIndex = 0;
            labelTipo.Text = "Tipo";
            // 
            // labelTaglia
            // 
            labelTaglia.AutoSize = true;
            labelTaglia.Location = new Point(39, 77);
            labelTaglia.Name = "labelTaglia";
            labelTaglia.Size = new Size(37, 15);
            labelTaglia.TabIndex = 1;
            labelTaglia.Text = "Taglia";
            labelTaglia.Click += labelTaglia_Click;
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(buttonCancella);
            groupBox1.Controls.Add(comboBoxTaglia);
            groupBox1.Controls.Add(comboBoxTipo);
            groupBox1.Controls.Add(labelTipo);
            groupBox1.Controls.Add(labelTaglia);
            groupBox1.Location = new Point(120, 12);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(382, 170);
            groupBox1.TabIndex = 2;
            groupBox1.TabStop = false;
            groupBox1.Text = "Descrizione articolo";
            // 
            // buttonCancella
            // 
            buttonCancella.Location = new Point(77, 124);
            buttonCancella.Name = "buttonCancella";
            buttonCancella.Size = new Size(244, 23);
            buttonCancella.TabIndex = 4;
            buttonCancella.Text = "Cancella voci";
            buttonCancella.TextAlign = ContentAlignment.BottomCenter;
            buttonCancella.UseVisualStyleBackColor = false;
            buttonCancella.Click += buttonCancella_Click;
            // 
            // comboBoxTaglia
            // 
            comboBoxTaglia.FormattingEnabled = true;
            comboBoxTaglia.Location = new Point(99, 77);
            comboBoxTaglia.Name = "comboBoxTaglia";
            comboBoxTaglia.Size = new Size(244, 23);
            comboBoxTaglia.TabIndex = 3;
            comboBoxTaglia.SelectedIndexChanged += comboBoxTaglia_SelectedIndexChanged;
            // 
            // comboBoxTipo
            // 
            comboBoxTipo.FormattingEnabled = true;
            comboBoxTipo.Location = new Point(99, 38);
            comboBoxTipo.Name = "comboBoxTipo";
            comboBoxTipo.Size = new Size(244, 23);
            comboBoxTipo.TabIndex = 2;
            comboBoxTipo.SelectedIndexChanged += comboBoxTipo_SelectedIndexChanged;
            // 
            // buttonInserisci
            // 
            buttonInserisci.Location = new Point(208, 213);
            buttonInserisci.Name = "buttonInserisci";
            buttonInserisci.Size = new Size(222, 23);
            buttonInserisci.TabIndex = 3;
            buttonInserisci.Text = "Inserisci in magazzino";
            buttonInserisci.UseVisualStyleBackColor = true;
            buttonInserisci.Click += buttonInserisci_Click;
            // 
            // groupBox2
            // 
            groupBox2.Controls.Add(buttonCerca);
            groupBox2.Controls.Add(textBoxElenco);
            groupBox2.Controls.Add(label1);
            groupBox2.Location = new Point(120, 266);
            groupBox2.Name = "groupBox2";
            groupBox2.Size = new Size(382, 172);
            groupBox2.TabIndex = 4;
            groupBox2.TabStop = false;
            groupBox2.Text = "Ricerca e visualizza";
            // 
            // buttonCerca
            // 
            buttonCerca.Location = new Point(109, 139);
            buttonCerca.Name = "buttonCerca";
            buttonCerca.Size = new Size(182, 23);
            buttonCerca.TabIndex = 2;
            buttonCerca.Text = "Cerca";
            buttonCerca.UseVisualStyleBackColor = true;
            buttonCerca.Click += buttonCerca_Click;
            // 
            // textBoxElenco
            // 
            textBoxElenco.Location = new Point(17, 60);
            textBoxElenco.Multiline = true;
            textBoxElenco.Name = "textBoxElenco";
            textBoxElenco.ScrollBars = ScrollBars.Vertical;
            textBoxElenco.Size = new Size(341, 66);
            textBoxElenco.TabIndex = 1;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(138, 30);
            label1.Name = "label1";
            label1.Size = new Size(118, 15);
            label1.TabIndex = 0;
            label1.Text = "Elenco articoli trovati";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(618, 450);
            Controls.Add(groupBox2);
            Controls.Add(buttonInserisci);
            Controls.Add(groupBox1);
            Name = "Form1";
            Text = "Form1";
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            groupBox2.ResumeLayout(false);
            groupBox2.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private Label labelTipo;
        private Label labelTaglia;
        private GroupBox groupBox1;
        private Button buttonCancella;
        private ComboBox comboBoxTaglia;
        private ComboBox comboBoxTipo;
        private Button buttonInserisci;
        private GroupBox groupBox2;
        private Button buttonCerca;
        private TextBox textBoxElenco;
        private Label label1;
    }
}
