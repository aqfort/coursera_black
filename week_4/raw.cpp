struct Student
{
  string name;
  int mark;
}

// This is placement new
alignas(Student) char buffer[1024];
Student *s = new (buffer) Student{"Alex", 5.0};
s->Print();
s->~Student();
// Единственный момент, когда деструктор нужно вызывать ручками!

char *buffer = new char[1024];
Student *s = new (buffer) Student{"Alex", 5.0};
s->Print();
s->~Student();
delete[] buffer;

// Запрос сырого участка памяти
void *buffer = operator new(sizeof(Student));
Student *s = new (buffer) Student{"Alex", 5.0};
s->Print();
s->~Student();
operator delete(buffer);

// Phoenix
Student s;
s.~Student();
new (&s) Student{"Alex", 5.0};
s.Print();
