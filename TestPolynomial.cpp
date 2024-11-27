#include "Assistance.h"	// ʵ�ó��������
#include "Polynomial.h"	// ����ʽ��
int main()
{
	char c = '1';
    Polynomial fa, fb, fc;
    PolyItem it;

    while (c != '0'){
        cout  <<"1. ���ɶ���ʽ." << endl;
        cout  <<"2. ��ʾ����ʽ." << endl;
        cout  <<"3. ����ʽ�ӷ�." << endl;
		cout  <<"4. ����ʽ��." << endl;
		cout  <<"5. ����ʽ�˷�." << endl;
		cout << "6. ����ʽ����." << endl;
		cout << "7. ����ʽ��ֵ." << endl;
		cout << "8. �ۺ�����." << endl;
		cout << "0. �˳�." << endl;
		cout  <<"ѡ����(0~8):" << endl;
		cin >> c;
		switch (c) {
		case '1':
			cout << endl << "����(coef, expn)(expn = -1ʱ�˳�):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn != -1) {
				fa.InsItem(it);
				cin >> it.coef >> it.expn;
			}
			break;
		case '2':
			fa.Display();
			cout << endl;
			break;
		case '3':
			// ����fa
			fa.SetZero();		// ��fa����Ϊ0
			cout << endl << "����fa����(coef, expn)(e = -1ʱ�˳�):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn != -1) {
				fa.InsItem(it);
				cin >> it.coef >> it.expn;
			}

			// ����fb
			fb.SetZero();		// ��fb����Ϊ0
			cout << endl << "����fb����(coef, expn)(e = -1ʱ�˳�):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn != -1) {
				fb.InsItem(it);
				cin >> it.coef >> it.expn;
			}

			fc = fa + fb;
			cout << "fa:" << endl;			// ��ʾfa
			fa.Display();
			cout << endl;

			cout << "fb:" << endl;			// ��ʾfa
			fb.Display();
			cout << endl;

			cout << "fa + fb:" << endl;		// ��ʾfc = fa + fb
			fc.Display();
			cout << endl;
			break;
			fa = fc;
		case '4':
			fa.SetZero();
			cout << endl << "����(coef, expn)(expn = -1ʱ�˳�):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn != -1) {
				fa.InsItem(it);
				cin >> it.coef >> it.expn;
			}
			fb = fa.d();
			cout << "fa:" << endl;			// ��ʾfa
			fa.Display();
			cout << endl;

			cout << "d(fa):" << endl;			// ��ʾfa
			fb.Display();
			cout << endl;
			break;
			fa = fb;
		case '5':
			fa.SetZero();		// ��fa����Ϊ0
			cout << endl << "����fa����(coef, expn)(e = -1ʱ�˳�):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn != -1) {
				fa.InsItem(it);
				cin >> it.coef >> it.expn;
			}

			// ����fb
			fb.SetZero();		// ��fb����Ϊ0
			cout << endl << "����fb����(coef, expn)(e = -1ʱ�˳�):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn != -1) {
				fb.InsItem(it);
				cin >> it.coef >> it.expn;
			}
			fc = fa * fb;
			cout << "fa:" << endl;			// ��ʾfa
			fa.Display();
			cout << endl;

			cout << "fb:" << endl;			// ��ʾfa
			fb.Display();
			cout << endl;

			cout << "fa * fb:" << endl;		// ��ʾfc = fa * fb
			fc.Display();
			cout << endl;
			break;
			fa = fc;
		case '6':
			// ����fa
			fa.SetZero();		// ��fa����Ϊ0
			cout << endl << "����fa����(coef, expn)(e = -1ʱ�˳�):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn != -1) {
				fa.InsItem(it);
				cin >> it.coef >> it.expn;
			}

			// ����fb
			fb.SetZero();		// ��fb����Ϊ0
			cout << endl << "����fb����(coef, expn)(e = -1ʱ�˳�):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn != -1) {
				fb.InsItem(it);
				cin >> it.coef >> it.expn;
			}

			fc = fa - fb;
			cout << "fa:" << endl;			// ��ʾfa
			fa.Display();
			cout << endl;

			cout << "fb:" << endl;			// ��ʾfa
			fb.Display();
			cout << endl;

			cout << "fa - fb:" << endl;		// ��ʾfc = fa - fb
			fc.Display();
			cout << endl;
			break;
			fa = fc;
		case '7':
			cout << endl << "����Ҫ����Ķ���ʽ��xֵ: ";
			int x;
			cin >> x;
			cout << "����ʽ��x = " << x << "����ֵΪ: " << fa.Evaluate(x) << endl;
			break;

		case '8':
			// ����fa
			fa.SetZero();		// ��fa����Ϊ0
			cout << endl << "����fa����(coef, expn)(e = -1ʱ�˳�):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn != -1) {
				fa.InsItem(it);
				cin >> it.coef >> it.expn;
			}

			// ����fb
			fb.SetZero();		// ��fb����Ϊ0
			cout << endl << "����fb����(coef, expn)(e = -1ʱ�˳�):" << endl;
			cin >> it.coef >> it.expn;
			while (it.expn != -1) {
				fb.InsItem(it);
				cin >> it.coef >> it.expn;
			}

			fc = fa + fb + fa.d() + fb.d();
			cout << "fa+fb+d(fa)+d(fb):" << endl;			// ��ʾfa
			fc.Display();
			cout << endl;
			fa = fc;
		}
	}
	system("PAUSE");				// ���ÿ⺯��system()
	return 0;						// ����ֵ0, ���ز���ϵͳ
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
