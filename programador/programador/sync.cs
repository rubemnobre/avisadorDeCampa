using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace programador
{
    public partial class sync : Form
    {
        public sync()
        {
            InitializeComponent();
        }

        public void setAviso(string aviso)
        {
            label1.Text = aviso;
        }

        private void sync_Load(object sender, EventArgs e)
        {
            
        }
    }
}
