using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.IO.Ports;

namespace programador
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private string porta = "COM1";
        private void Form1_Load(object sender, EventArgs e)
        {
            string[] dias =
            {
                "segunda","terça","quarta","quinta","sexta"
            };
            string[] nome =
            { "bio", "ef ", "el2", "ed ", "e2 ", "fil", "fis",
              "geo", "his", "mat", "qui", "soc", "por", "art",
              "ing", "ons",
            };
            for (int i = 0;i < 7; i++)
            {
                comboBox2.Items.Add(i+1);
            }
            foreach(string aa in dias)
            {
                comboBox3.Items.Add(aa);
            }
            foreach (string aa in nome)
            {
                comboBox4.Items.Add(aa);
            }

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            porta = comboBox1.Text;
        }

        private void comboBox1_DropDown(object sender, EventArgs e)
        {
            string[] portas;
            portas = SerialPort.GetPortNames();
            comboBox1.Items.Clear();
            foreach (string str in portas)
            {
                comboBox1.Items.Add(str);
            }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            porta = comboBox1.Text;
            int dia = Convert.ToInt32(DateTime.Now.DayOfWeek);
            if(dia == 0)
            {
                dia = 7;
            }
            int hora = DateTime.Now.Hour;
            long min  = DateTime.Now.Minute;
            long minuto = hora * 60 + min;
            long millis = 0;
            try
            {
                millis = minuto * 60000 + (DateTime.Now.Second + Convert.ToInt32(textBox1.Text)) * 1000 + DateTime.Now.Millisecond;
            }
            catch
            {
                millis = minuto * 60000 + (DateTime.Now.Second) * 1000 + DateTime.Now.Millisecond;
            }
            bool good = false;
            label5.Text = "";
            try
            {
                SerialPort arduino = new SerialPort(porta, 9600);
                arduino.ReadTimeout = 200;
                arduino.DtrEnable = false;
                arduino.Open();
                arduino.Write("t");
                arduino.ReadExisting();
                arduino.Write(Convert.ToString(millis)+"~");
                arduino.Write(Convert.ToString(dia)+"~");
                arduino.Close();
                good = true;
            }
            catch {
            }
            if (good)
            {
                label5.Text = "Pronto!";
            }
            else
            {
                label5.Text = "Erro!";
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            porta = comboBox1.Text;
            int tempo = 0, materia = 0, dia = 0;
            int tl = -1;
            try
            {
                tl = Convert.ToInt32(comboBox2.Text);
            }
            catch
            {

            }
            if (tl <= 2)
            {
                tempo = tl;
            }
            if (tl >= 3 && tl <= 4)
            {
                tempo = tl + 1;
            }
            if (tl >= 5 && tl <= 7)
            {
                tempo = tl + 3;
            }
            materia = comboBox4.SelectedIndex;
            dia = comboBox3.SelectedIndex;
            bool good = false;
            label5.Text = "";
            try
            {
                SerialPort arduino = new SerialPort(porta, 9600);
                arduino.ReadTimeout = 200;
                arduino.DtrEnable = false;
                arduino.Open();
                arduino.Write("s");
                arduino.ReadExisting();
                arduino.Write(Convert.ToString(materia) + "~");
                arduino.Write(Convert.ToString(tempo) + "~");
                arduino.Write(Convert.ToString(dia) + "~");
                arduino.Close();
                good = true;
            }
            catch
            {
                
            }
            if (good == true)
            {
                label5.Text = "Pronto!";
            }
            else
            {
                label5.Text = "Erro!";
            }
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }
    }
}
