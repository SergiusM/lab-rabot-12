#include <iostream>
#include <memory> 
#include <string>
//#define MY_DEBUG

class Teacher;
class student 
{
public:
	student(const std::string& name) 
	{
		m_name = name;
#ifdef MY_DEBUG
		std::cout << "Student +" << std::endl;
#endif
	}
	~student() 
	{
#ifdef MY_DEBUG
		std::cout << "Student -" << std::endl;
#endif
	}

	std::string NameS() { return m_name; }
	std::shared_ptr<student> GetT() { m_teacher; }

	friend void teach(std::shared_ptr<Teacher>& T, std::shared_ptr<student>& S);

private:
	std::string m_name;
	std::shared_ptr<Teacher> m_teacher;
};
class Teacher 
{
public:
	Teacher(const std::string& name) 
	{
		m_name = name;
		m_i = -1;
#ifdef MY_DEBUG
		std::cout << "Teacher +" << std::endl;
#endif
	}
	~Teacher() 
	{
#ifdef MY_DEBUG
		std::cout << "Teacher -" << std::endl;
#endif
	}
	std::string NameT() { return m_name; }
	std::shared_ptr<student> GetS() 
	{
		return (m_student[m_i]);
	}
	int all() 
	{
		return(m_i);
	}

	void allstudent() 
	{
		for (int i = 0; i < m_i; i++) 
			std::cout << m_student[m_i];
	}

	void addstudent() 
	{
		m_i = m_i + 1;
#ifdef MY_DEBUG
		std::cout << "Student create" << std::endl;
#endif
	}

	friend void teach(std::shared_ptr<Teacher>& T, std::shared_ptr<student>& S);

private:
	std::string m_name;
	int m_i;
	std::shared_ptr<student> m_student[10];

};

void teach(std::shared_ptr<Teacher>& T, std::shared_ptr<student>& S) 
{
	T->addstudent();
	S->m_teacher = T;
	T->GetS() = S;
	std::cout << T->m_name << " teach " << S->m_name << std::endl;
}

int main()
{
	std::shared_ptr<student> student1 = std::make_shared<student>("Anton");
	std::shared_ptr<student> student2 = std::make_shared<student>("Maksim");
	std::shared_ptr<Teacher> teacher = std::make_shared<Teacher>("Misha");
	teach(teacher, student1);
	teach(teacher, student2);
}