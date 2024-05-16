#include <iostream>
using namespace std;

class Employee {};
class DaoEmployee {
public:
    ~DaoEmployee(){}
    virtual void insert(const Employee& e) = 0;
    virtual Employee select(int id) = 0;
};

class SQLServerEmployee : public DaoEmployee {
public:
    void insert(const Employee& e) override {
        cout << "SQLServer insert employee ..." << endl;
    }
    Employee select(int id) override {
        cout << "SQLServer select employee ..." << endl;
        return Employee();
    }
};

class OracleEmployee : public DaoEmployee {
public:
    void insert(const Employee& e) override {
        cout << "Oracle insert employee ..." << endl;
    }
    Employee select(int id) override {
        cout << "Oracle select employee ..." << endl;
        return Employee();
    }
};

class Dept{};
class DaoDept {
public:
    virtual ~DaoDept(){}
    virtual void insert(const Dept& d) = 0;
    virtual Dept select(int id) = 0;
};

class SQLServerDept : public DaoDept {
public:
    void insert(const Dept& e) override {
        cout << "SQLServer insert dept ..." << endl;
    }
    Dept select(int id) override {
        cout << "SQLServer select dept ..." << endl;
        return Dept();
    }
};

class OracleDept : public DaoDept {
public:
    void insert(const Dept& e) override {
        cout << "Oracle insert dept ..." << endl;
    }
    Dept select(int id) override {
        cout << "Oracle select dept ..." << endl;
        return Dept();
    }
};

class DaoFactory{
public:
    virtual ~DaoFactory() {}
    virtual DaoEmployee* createEmployee() = 0;
    virtual DaoDept* createDept() = 0;
};

class SQLServerFactory : public DaoFactory {
public:
    DaoEmployee* createEmployee() override {
        return new SQLServerEmployee();
    }

    DaoDept* createDept() override {
        return new SQLServerDept();
    }
};

class OracleFactory : public DaoFactory {
public:
    OracleEmployee* createEmployee() override {
        return new OracleEmployee();
    }

    OracleDept* createDept() override {
        return new OracleDept();
    }
};

class Client {
public:
    Client( DaoFactory* factory) : m_factory(factory) {}

    void business() const {
        Employee employee;
        DaoEmployee* daoEmployee = m_factory->createEmployee();
        daoEmployee->insert(employee);
        daoEmployee->select(1001);
        delete daoEmployee;

        Dept dept;
        DaoDept* daoDept = m_factory->createDept();
        daoDept->insert(dept);
        daoDept->select(1010);
        delete daoDept;
    }

private:
    DaoFactory* m_factory;
};

int main() {
    //OracleFactory factory;
    SQLServerFactory factory;
    Client client(&factory);
    client.business();


    return 0;
}
