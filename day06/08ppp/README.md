## 继承方式与访问控制

* 类成员的访问控制限定符与访问控制属性

  | 访问控制限定符   | 访问控制属性 | 基类 | 子类 | 外部 | 友元 |
    |-----------|--------|----|----|----|----|
  | public    | 公有成员   | OK | OK | OK | OK |
  | protected | 保护成员   | OK | OK | NO | OK |
  | private   | 私有成员   | OK | NO | NO | OK |

* 基类中的公有、保护和私有成员，在其公有、保护和私有子类中的访问控制属性，会因继承方式而异

  | 基类中的 | 在公有子类（公有继承）中变成 | 在保护子类（保护继承）中变成 | 在私有子类（私有继承）中变成 |
    |------|----------------|----------------|----------------|
  | 公有成员 | 公有成员           | 保护成员           | 私有成员           |
  | 保护成员 | 保护成员           | 保护成员           | 私有成员           |
  | 私有成员 | 私有成员           | 私有成员           | 私有成员           |

* 当通过子类访问其所继承的基类的成员时，需要考虑继承方式对访问控制属性的影响

## private,protected的作用是防止接口扩散
```c++
class DCT {
public:
    void codec() {
        //...
    }
};

class Jpeg : public DCT {
public:
    void render() {
        //...
        render();
        //...
    }    
};

Jpeg j;
j.codec(); // 接口扩散了
```
```c++
class DCT {
public:
    void codec() {
        //...
    }
};

class Jpeg : private DCT {
public:
    void render() {
        //...
        render();
        //...
    }    
};

Jpeg j;
// 防止扩散
j.codec(); // ERROR
```

```c++
class DCT {
public:
    void codec() {
        //...
    }
};

class Jpeg : private DCT {
public:
    void render() {
        //...
        render();
        //...
    }    
};

class PDF : public Jpeg{};

PDF pdf;
pdf.codec(); //有限的扩散
```