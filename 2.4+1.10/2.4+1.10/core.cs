using System.ComponentModel;
namespace _2._4_1._10Models
{
    public class Lab : INotifyPropertyChanged
    {
        string faculty, name;
        int age, semester, gpa;
        public Lab()
        {
            name = faculty = "0";
            age = semester = gpa = 0;
        }
        public Lab(string name, string faculty, int age, int semester, int gpa)
        {
            this.name = name;
            this.faculty = faculty;
            this.age = age;
            this.semester = semester;
            this.gpa = gpa;
        }
        public string Name
        {
            get { return name; }
            set
            {
                if (name == value)
                    return;
                name = value;
                OnPropertyChanged("Name");
            }
        }
        public string Faculty
        {
            get { return faculty; }
            set
            {
                if (faculty == value)
                    return;
                faculty = value;
                OnPropertyChanged("faculty");
            }
        }
        public int Age
        {
            get { return age; }
            set
            {
                if (age == value)
                    return;
                age = value;
                OnPropertyChanged("age");
            }
        }
        public int Gpa
        {
            get { return gpa; }
            set
            {
                if (gpa == value)
                    return;
                gpa = value;
                OnPropertyChanged("gpa");
            }
        }
        public int Semester
        {
            get { return semester; }
            set
            {
                if (semester == value)
                    return;
                semester = value;
                OnPropertyChanged("semester");
            }
        }
        public event PropertyChangedEventHandler PropertyChanged;
        protected virtual void OnPropertyChanged(string propertyName = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
    public class nasled_lab : Lab
    {
        int group, well;
        public int Group
        {
            get { return group; }
            set
            {
                if (group == value)
                    return;
                group = value;
                OnPropertyChanged("group");
            }
        }
        public int Well
        {
            get { return well; }
            set
            {
                if (well == value)
                    return;
                well = value;
                OnPropertyChanged("Number");
            }
        }
        public nasled_lab() : base() { group = 0; well = 0; }
        public nasled_lab(string name, string faculty, int age, int semester, int gpa, int
        group, int well)
        : base(name, faculty, age, semester, gpa)
        {
            this.group = group;
            this.well = well;
        }
        public int YearCalc()
        {
            int a = 2024 - well;
            return a;
        }
    }
}