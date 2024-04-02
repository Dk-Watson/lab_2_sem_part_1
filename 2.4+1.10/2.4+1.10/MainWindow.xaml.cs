using System;
using System.Windows;
using System.ComponentModel;
using _2._4_1._10Models;
using _2._4_1._10Services;
namespace _2._4_1._10
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private readonly string PATH;
        private BindingList<nasled_lab> DataList;
        private IOfile service;
        public MainWindow()
        {
            InitializeComponent();
            PATH = $"{Environment.CurrentDirectory}\\DataList.json";
            dgLab.Loaded += dgLab_Loaded;
        }

        private void dgLab_Loaded(object sender, RoutedEventArgs e)
        {
            service = new IOfile(PATH);
            DataList = service.LoadData();
            dgLab.ItemsSource = DataList;
            DataList.ListChanged += DataList_ListChanged;
        }
        private void DataList_ListChanged(object sender, ListChangedEventArgs e)
        {
            if (e.ListChangedType == ListChangedType.ItemAdded || e.ListChangedType == ListChangedType.ItemDeleted || e.ListChangedType == ListChangedType.ItemChanged)
            {
                service.SaveData(DataList);
            }
        }
    }
}