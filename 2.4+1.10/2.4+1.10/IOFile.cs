using _2._4_1._10Models;
using Newtonsoft.Json;
using System.ComponentModel;
using System.IO;
namespace _2._4_1._10Services
{
    internal class IOfile
    {
        private readonly string PATH;
        public IOfile(string path)
        {
            PATH = path;
        }
        public BindingList<nasled_lab> LoadData()
        {
            var fileExists = File.Exists(PATH);
            if (!fileExists)
            {
                File.CreateText(PATH).Dispose();
                return new BindingList<nasled_lab>();
            }
            using (var reader = File.OpenText(PATH))
            {
                var fileText = reader.ReadToEnd();
                return JsonConvert.DeserializeObject<BindingList<nasled_lab>>(fileText);
            }
        }
        public void SaveData(object DataList)
        {
            using (StreamWriter writer = File.CreateText(PATH))
            {
                string output = JsonConvert.SerializeObject(DataList);
                writer.WriteLine(output);
            }
        }
    }
}
