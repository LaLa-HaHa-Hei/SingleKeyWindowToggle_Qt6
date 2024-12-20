#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // 表格中选项框点击
    void onCheckboxToggled(bool checked, HWND hwnd);
    // 打开关于窗口
    void on_actionOpenAboutDialog_triggered();
    // 刷新表格
    void on_pushButtonRefreshTableWidgetWindowInfo_clicked();
    // 显示所以选中的窗口
    void on_pushButtonShowCheckedWindow_clicked();
    // 注册快捷键
    void on_pushButtonStart_clicked();
    // 取消注册快捷键
    void on_pushButtonStop_clicked();
    // 打开微软的虚拟键代码网站
    void on_pushButtonOpenMSURL_clicked();

private:
    Ui::MainWindow *ui;
    // 目标窗口信息
    struct TargetWindowInfo
    {
        HWND hwnd;
        bool visible;
    };
    // 要隐藏显示的窗口句柄列表
    QList<TargetWindowInfo> _targetWindowHandleList;
    // 鼠标钩子id
    HHOOK _hookId = NULL;
    // 虚拟键码
    UINT _virtualKeyCode;
    // 刷新窗口信息表格
    void RefreshTableWidgetWindowInfo();
    // 遍历所有窗口，显示到表格中
    static BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);
    // 键盘钩子回调函数
    static LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
    // 隐藏目标窗口
    static void HideTargetWindow(HWND hwnd, bool byTransparency);
    // 显示目标窗口
    static void ShowTargetWindow(HWND hwnd, bool byTransparency);
    // 切换目标窗口状态
    void ToggleWindowsVisibility();
};
#endif // MAINWINDOW_H
