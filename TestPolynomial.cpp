#include "Assistance.h"	// 实用程序软件包
#include "Polynomial.h"	// 多项式类
int main()
{
	char c = '1';
    Polynomial fa, fb, fc;
    PolyItem it;
    while (c != '0'){
		bool astatus = fa.IsZero(),bstatus=fb.IsZero();
        cout  <<"1. 输入多项式." << endl;
        cout  <<"2. 显示多项式." << endl;
        cout  <<"3. 多项式加法." << endl;
		cout  <<"4. 多项式求导." << endl;
		cout  <<"5. 多项式乘法." << endl;
		cout << "6. 多项式减法." << endl;
		cout << "7. 多项式求值." << endl;
		cout << "8. 综合运算." << endl;
		cout << "0. 退出." << endl;
		cout  <<"选择功能(0~8):" << endl;
		cin >> c;
		switch (c) {
		case '1':
			// 输入fa
			fa.SetZero();		// 将fa设置为0
			cout << endl << "输入fa的项(coef, expn)(e <0 时退出):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn >=0) {
				fa.InsItem(it);
				cin >> it.coef >> it.expn;
			}
			// 输入fb
			fb.SetZero();		// 将fb设置为0
			cout << endl << "输入fb的项(coef, expn)(e <0 时退出):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn >=0) {
				fb.InsItem(it);
				cin >> it.coef >> it.expn;
			}
			break;
		case '2':
			if (astatus && bstatus) {
				puts("请输入fa或者fb!");
				break;
			}
			if (!astatus) {
				cout << "fa:" << endl;
				fa.Display();
				cout << endl;
			}
			if (!bstatus) {
				cout << "fb:" << endl;
				fb.Display();
				cout << endl;
			}
			break;
		case '3':
			if (astatus || bstatus) {
				puts("请输入fa和fb!");
				break;
			}
			fc = fa + fb;
			cout << "fa:" << endl;			// 显示fa
			fa.Display();
			cout << endl;

			cout << "fb:" << endl;			// 显示fa
			fb.Display();
			cout << endl;

			cout << "fa + fb:" << endl;		// 显示fc = fa + fb
			fc.Display();
			cout << endl;
			break;
		case '4':
			if (astatus || bstatus) {
				puts("请输入fa和fb!");
				break;
			}
			fc = fa.d();
			cout << "fa:" << endl;			// 显示fa
			fa.Display();
			cout << endl;
			cout << "fb:" << endl;			// 显示fa
			fb.Display();
			cout << endl;

			cout << "d(fa):" << endl;			// 显示d(fa)
			fc.Display();
			cout << endl;
			fc = fb.d();
			cout << "d(fb)" << endl;		//显示d(fb)
			fc.Display();
			cout << endl;
			break;
		case '5':
			if (astatus || bstatus) {
				puts("请输入fa和fb!");
				break;
			}
			fc = fa * fb;
			cout << "fa:" << endl;			// 显示fa
			fa.Display();
			cout << endl;

			cout << "fb:" << endl;			// 显示fa
			fb.Display();
			cout << endl;

			cout << "fa * fb:" << endl;		// 显示fc = fa * fb
			fc.Display();
			cout << endl;
			break;
		case '6':
			if (astatus || bstatus) {
				puts("请输入fa和fb!");
				break;
			}
			fc = fa - fb;
			cout << "fa:" << endl;			// 显示fa
			fa.Display();
			cout << endl;

			cout << "fb:" << endl;			// 显示fa
			fb.Display();
			cout << endl;

			cout << "fa - fb:" << endl;		// 显示fc = fa - fb
			fc.Display();
			cout << endl;
			break;
		case '7':
			if (astatus || bstatus) {
				puts("请输入fa和fb!");
				break;
			}
			cout << endl << "输入要计算的多项式的x值: ";
			int x;
			cin >> x;
			cout << "多项式a在x = " << x << "处的值为: " << fa.Evaluate(x) << endl;
			cout << "多项式b在x = " << x << "处的值为: " << fb.Evaluate(x) << endl;
			cout << "多项式c在x = " << x << "处的值为: " << fc.Evaluate(x) << endl;
			break;
		case '8':
			if (astatus || bstatus) {
				puts("请输入fa和fb!");
				break;
			}
			fc = fa + fb + fa.d() + fb.d();
			cout << "fa+fb+d(fa)+d(fb):" << endl;			// 显示fa
			fc.Display();
			cout << endl;
			break;
		default:
			break;
		}
	}
	system("PAUSE");				// 调用库函数system()
	return 0;						// 返回值0, 返回操作系统
}
/*
2 0
3 1
2 2
3 -1

1 0
2 1
3 2
4 -1
*/
