//
//  main.cpp
//  排序
//
//  Created by bondsam on 30/05/2018.
//  Copyright © 2018 bondsam. All rights reserved.
//
#include <iostream>
using namespace std;
int qcompare=0;
int qmove=0;
void InsertSort(int r[],int n)
{
    int move=0;
    int compare=0;
    int a[n+1];
    a[0]=0;
    for (int i=1; i<=n; i++) {
        a[i]=r[i-1];
    }
    for (int i =2; i<=n; i++) {
        compare++;
        if (a[i-1]>a[i]) {
            a[0]=a[i];
            int j=i-1;
            for (; a[0]<a[j]; j--) {
                a[j+1]=a[j];
                move++;
                compare++;
            }
            a[j+1]=a[0];
        }
    }
    cout<<"插入排序"<<endl;
    cout<<"排序后数列"<<":";
    for (int i =1; i<=n; i++) {
        cout<<a[i]<<' ';
    }
    cout<<endl;
    cout<<"比较次数"<<compare<<endl;
    cout<<"交换次数"<<move<<endl;
}
void Shell(int r[], int n)
{
    int compare = 0;
    int move = 0;
    int j;
    for (int d = n / 2; d >= 1; d = d / 2)
    {
        for (int i = d; i < n; i++)
        {
            if (r[i] < r[i - d])
            {
                int x = r[i];
                for (j = i - d; (j >= 0) && (x < r[j]); j = j - d)//同上插入排序
                {
                    compare++;
                    move++;
                    r[j + d] = r[j];
                }
                if(j>=0)
                compare++;
                r[j + d] = x;
            }
            else
            compare++;
        }
    }

    cout<<"希尔排序"<<endl;
    cout<<"排序后数列"<<":";
    for (int i =0; i<n; i++) {
        cout<<r[i]<<' ';
    }
    cout<<endl;
    cout<<"比较次数"<<compare<<endl;
    cout<<"交换次数"<<move<<endl;
}
void Bubble(int r[],int n)
{
    int compare=0;
    int move=0;
    int temp;
    for (int i =0; i<n; i++) {
        for (int j=0; j<n-i; j++) {
            compare++;
            if (r[j]>r[j+1]&&j<n-1) {
                move+=3;
                temp=r[j];
                r[j]=r[j+1];
                r[j+1]=temp;
                
            }
        }
        compare--;
    }
    cout<<"冒泡排序"<<endl;
    cout<<"排序后数列"<<":";
    for (int i =0; i<n; i++) {
        cout<<r[i]<<' ';
    }
    cout<<endl;
    cout<<"比较次数"<<compare<<endl;
    cout<<"交换次数"<<move<<endl;
}
int Partion(int r[],int first,int end)
{
    int i=first;
    int j=end;
    int pivot=r[i];
    while (i<j) {
        while ((i<j)&&(r[j]>=pivot)) {
            j--;
            qcompare++;
        }
        if (i!=j) {
            r[i]=r[j];
            qcompare++;
            qmove++;
        }
        while ((i<j)&&(r[i]<=pivot)) {
            i++;
            qcompare++;
        }
        if (i!=j) {
            r[j]=r[i];
            qmove++;
            qcompare++;
        }
    }
    r[i]=pivot;
    return i;
}
void Qsort(int r[],int i,int j)
{
    if(i<j)
    {
        int pivotloc=Partion(r, i, j);
        Qsort(r, i, pivotloc-1);
        Qsort(r, pivotloc+1, j);
    }
    
}
void QsortPrint(int r[],int n)
{
    Qsort(r, 0, n-1);
    cout<<"快速排序"<<endl;
    cout<<"排序后数列"<<":";
    for (int i=0; i<n; i++) {
        cout<<r[i]<<' ';
    }
    cout<<endl;
    cout<<"比较次数"<<qcompare<<endl;
    cout<<"交换次数"<<qmove<<endl;
    
}
void EasySelect(int r[],int n)
{
    int compare=0;
    int move=0;
    int a[n+1];
    a[0]=0;
    for (int i=1; i<=n; i++) {
        a[i]=r[i-1];
    }
    for (int i=0; i<n; i++) {
        int index=i;
        for (int j=i+1; j<=n; j++) {
            compare++;
            if (a[j]<a[index]) {
                index=j;
            }
        }
        compare--;
        if (index!=i) {
            a[0]=a[i];
            a[i]=a[index];
            a[index]=a[0];
            move+=3;
        }
    }
    cout<<"简单选择排序"<<endl;
    cout<<"排序后数列"<<":";
    for (int i =1; i<=n; i++) {
        cout<<a[i]<<' ';
    }
    cout<<endl;
    cout<<"比较次数"<<compare<<endl;
    cout<<"交换次数"<<move<<endl;
}
int main()
{
    int n;
    cout<<"请输入数列的长度 \n";
    cin>>n;
    int r[n];
    cout<<"请输入数列 "<<endl;
    for (int i=0; i<n; i++) {
        cin>>r[i];
    }
    cout<<"生成排序 \n\n\n";
            InsertSort(r, n);
            cout<<endl<<endl;


            Shell(r, n);
            cout<<endl<<endl;

            Bubble(r, n);
            cout<<endl<<endl;

            QsortPrint(r,n);
            cout<<endl<<endl;

            EasySelect(r,n);
            cout<<endl<<endl;

    
    
}
