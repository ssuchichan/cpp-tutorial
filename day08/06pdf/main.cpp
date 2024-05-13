#include <iostream>
using namespace std;

// 模板方法模式（好莱坞模式）
class PDFParser {
public:
    void parse(const char* pdffile) {
        // 解析矩形
        // ...
        this->onRect();

        // 解析圆
        // ...
        onCircle();

        // 解析文字
        // ...
        onText();

        // 解析图片
        // ...
        onImage();
    }

private:
    virtual void onRect() = 0;
    virtual void onCircle() = 0;
    virtual void onText() = 0;
    virtual void onImage() = 0;
};

class PDFRender : public PDFParser {
private:
    void onRect() override {
        cout << "draw Rect" << endl;
    }
    void onCircle() override {
        cout << "draw Circle" << endl;
    }
    void onText() override {
        cout << "draw Text" << endl;
    }
    void onImage() override {
        cout << "draw Image" << endl;
    }
};

int main() {
    PDFRender render;
    // 发生多态
    render.parse("something.pdf");

    return 0;
}
