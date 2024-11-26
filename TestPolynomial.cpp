#include "Assistance.h"	// 实用程序软件包
#include "Polynomial.h"	// 多项式类
int main()
{
	char c = '1';
    Polynomial fa, fb, fc;
    PolyItem it;

    while (c != '0'){
        cout  <<"1. 生成多项式." << endl;
        cout  <<"2. 显示多项式." << endl;
        cout  <<"3. 多项式加法." << endl;
		cout  <<"4. 多项式求导." << endl;
		cout  <<"5. 多项式加法." << endl;
		cout << "6. 多项式减法." << endl;
		cout << "7. 多项式求值." << endl;
		cout << "0. 退出." << endl;
		cout  <<"选择功能(0~7):" << endl;
		cin >> c;
		switch (c) {
		case '1':
			cout << endl << "输入(coef, expn)(expn = -1时退出):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn != -1) {
				fa.InsItem(it);
				cin >> it.coef >> it.expn;
			}
			break;
		case '2':
			fa.Display();
			break;
		case '3':
			// 输入fa
			fa.SetZero();		// 将fa设置为0
			cout << endl << "输入fa的项(coef, expn)(e = -1时退出):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn != -1) {
				fa.InsItem(it);
				cin >> it.coef >> it.expn;
			}

			// 输入fb
			fb.SetZero();		// 将fb设置为0
			cout << endl << "输入fb的项(coef, expn)(e = -1时退出):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn != -1) {
				fb.InsItem(it);
				cin >> it.coef >> it.expn;
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
			cout << endl << "输入(coef, expn)(expn = -1时退出):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn != -1) {
				fa.InsItem(it);
				cin >> it.coef >> it.expn;
			}
			fb = fa.d();
			cout << "fa:" << endl;			// 显示fa
			fa.Display();
			cout << endl;

			cout << "fb:" << endl;			// 显示fa
			fb.Display();
			cout << endl;
			break;
		case '5':
			fa.SetZero();		// 将fa设置为0
			cout << endl << "输入fa的项(coef, expn)(e = -1时退出):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn != -1) {
				fa.InsItem(it);
				cin >> it.coef >> it.expn;
			}

			// 输入fb
			fb.SetZero();		// 将fb设置为0
			cout << endl << "输入fb的项(coef, expn)(e = -1时退出):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn != -1) {
				fb.InsItem(it);
				cin >> it.coef >> it.expn;
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
			// 输入fa
			fa.SetZero();		// 将fa设置为0
			cout << endl << "输入fa的项(coef, expn)(e = -1时退出):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn != -1) {
				fa.InsItem(it);
				cin >> it.coef >> it.expn;
			}

			// 输入fb
			fb.SetZero();		// 将fb设置为0
			cout << endl << "输入fb的项(coef, expn)(e = -1时退出):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn != -1) {
				fb.InsItem(it);
				cin >> it.coef >> it.expn;
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
			cout << endl << "输入要计算的多项式的x值: ";
			int x;
			cin >> x;
			cout << "多项式在x = " << x << "处的值为: " << fa.Evaluate(x) << endl;
			break;
		}
	}
	system("PAUSE");				// 调用库函数system()
	return 0;						// 返回值0, 返回操作系统
}
