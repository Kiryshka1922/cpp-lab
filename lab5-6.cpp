#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
void show_menu_format();
void show_menu();
class Matrix{
static int format;
static int count;
int rows{0};
int cols{0};
double **arr{nullptr};
friend void show_menu_format();
public:
Matrix(int r, int w){
    this->rows=r;
    this->cols=w;
    this->arr = new double* [rows];
    for (int i=0; i<rows; i++){
        arr[i]= new double [cols]{0};}
}
Matrix(int format){
if (format==1){
    cout<<"Введите матрицу: ";
    cin>>this->rows>>this->cols;
    arr = new double* [rows];
    for (int i=0; i<rows; i++){
        arr[i]= new double [cols]{0};}
    for (size_t t=0; t<this->rows; t++){
        for (size_t i=0; i<this->cols; i++){
            cin>>arr[t][i];}}}
if (format==2){
    count++;
    std::fstream ifs("read.txt");
    if(count==2){
        std::string dummyLine;
        getline(ifs, dummyLine);}
    cout<<"Читаю данные из файла . . .\n";
    if (ifs.is_open()){
        ifs>>this->rows>>this->cols;
        arr = new double* [rows];
            for (int i=0; i<rows; i++){
                arr[i]= new double [cols]{0};}
                 for (size_t t=0; t<this->rows; t++){
                for (size_t i=0; i<this->cols; i++){
                    ifs>>arr[t][i];}}}
    else cout<<"К сожалению, файл не был открыт.";}
}
Matrix()=default;
~Matrix(){
    for (int i=0; i<rows; i++){
        delete [] arr[1];}
    delete [] arr;    
}
int get_cols()const;
int get_rows()const;
static int get_format();
double** get_arr()const {
    return this->arr;
}
class Item{
    const Matrix * current;
    int index;
    public:
    Item(const Matrix*ptr, int ind): current(ptr), index(ind){}
    double& operator[](int ind){
        return current->get_arr()[index][ind];
    }};
Item operator [](int ind)const{
    return Item(this, ind);}
void show_mtr(){
    for (int t=0; t<this->get_rows(); t++){
        if (t) cout<<'\n';
        for (int i=0; i<this->get_cols(); i++){
            cout<<this->get_arr()[t][i]<<" ";}}}
Matrix operator +(const Matrix& right){
if (this->get_rows()!=right.get_rows() || this->get_cols()!=this->get_cols()){
    cout<<"Матрицы не подходящие для операции сложения !\n";
    return *this;}
Matrix res(this->get_rows(), this->get_cols());
for (size_t t=0; t<res.get_rows(); t++){
    for (size_t i=0; i<res.get_cols(); i++){
        res.get_arr()[t][i]=this->get_arr()[t][i]+right.get_arr()[t][i];
    }}
    return res;}
Matrix& operator = (const Matrix &right){
    if (!(this->get_arr())) this->~Matrix();
    this->rows=right.get_rows();
    this->cols=right.get_cols();
    this->arr = new double* [rows];
    for (int i=0; i<this->rows; i++){
        arr[i]= new double [cols]{0};}
    for (size_t t=0; t<this->rows; t++){
        for (size_t i=0; i<this->cols; i++){
        this->arr[t][i]=right.get_arr()[t][i];
    }}
    return *this;    
    }    
Matrix operator -(const Matrix& right){
if (this->get_rows()!=right.get_rows() || this->get_cols()!=this->get_cols()){
    cout<<"Матрицы не подходящие для операции вычитания !\n";
    return *this;}
Matrix res(this->get_rows(), this->get_cols());
for (size_t t=0; t<res.get_rows(); t++){
    for (size_t i=0; i<res.get_cols(); i++){
        res.get_arr()[t][i]=this->get_arr()[t][i]-right.get_arr()[t][i];
    }}
    return res;}
Matrix operator * (int a){
Matrix res(this->get_rows(), this->get_cols());
for (size_t t=0; t<res.get_rows(); t++){
    for (size_t i=0; i<res.get_cols(); i++){
        res.get_arr()[t][i]=this->get_arr()[t][i]*a;
    }}
    return res;
}
Matrix operator * (const Matrix& right){
    if (this->get_cols()!=right.get_rows()){
    cout<<"Матрицы не подходящие для операции умножения !\n";
    return *this;}
Matrix res(this->get_rows(), right.get_cols());
for (size_t t=0; t<this->get_rows(); t++){
    for (size_t i=0; i<this->get_cols(); i++){
        for (size_t r=0; r<right.get_cols();r++){
            res.arr[t][r]+=this->get_arr()[t][i]*right.arr[i][r];
        }
    }}
    return res;
}
bool operator ==(const Matrix& right){
if (this->get_cols()!=right.get_cols() || this->get_rows()!=right.get_rows()){
    return false;
}
for (size_t t=0; t<this->get_rows(); t++){
    for (size_t i=0; i<this->get_cols(); i++){
        if (arr[t][i]!=right.get_arr()[t][i]){return false;}
    }}
return true;
}
bool operator != (const Matrix right){
if (this->get_cols()!=right.get_cols() || this->get_rows()!=right.get_rows()){
    return true;
}
for (size_t t=0; t<this->get_rows(); t++){
    for (size_t i=0; i<this->get_cols(); i++){
        if (arr[t][i]!=right.get_arr()[t][i]){return true;}
    }}
return false;
}
bool operator ==(double pr){
for (size_t t=0; t<this->get_rows(); t++){
    for (size_t i=0; i<this->get_cols(); i++){
        if (t==i)
        {   if(this->arr[i][t]!=pr)
            return false;}
        else {
            if (this->arr[i][t]!=0)
            return false;
        }}}
return true;
}
};
int Matrix::format=-1;
int Matrix::count=0;
int main (){
    setlocale(LC_ALL, "Russian");
    show_menu_format();
    Matrix mtr_1(Matrix::get_format());
    //mtr_1=mtr_1 * 10;
    mtr_1.show_mtr();
    cout<<"\n";
    Matrix mtr_2(Matrix::get_format());
    mtr_2.show_mtr();
    cout<<"\n";
// cout<<mtr_1.get_cols()<< mtr_1.get_rows() <<mtr_2.get_cols()<<mtr_2.get_rows();
    Matrix mtr_3 = mtr_1 * mtr_2;
//cout<<mtr_3.get_rows()<<" "<<mtr_3.get_cols();
// for (int t=0;t<2;t++){
//     for (int i=0; i<2;i++){
//     cout<<mtr_3.get_arr()[0][1];}
// }
   // mtr_3.show_mtr();
bool res = mtr_2 == 5;
//cout<<mtr_3.get_arr()[0][0]<<" "<<mtr_3.get_arr()[0][1]<<" "<<mtr_3.get_arr()[1][0]<<" "<<mtr_3.get_arr()[1][1];
cout<<res;
    
}




void show_menu(){
int do_it{0};
cout<<"Что сделать матрицами?\n";
cout<<"1 - Перемножить\t"<<"2 - Сложить\t"<<"3 - Вычесть\t"<<"4 - Сравнить на равенство\t";
cin>>do_it; 
while(do_it!=1 && do_it!=2 && do_it!=3 && do_it!=4){
cout<<"Неверное значение, введите заново:\n";
cin>>do_it;}
if (do_it==1){
    Matrix res;}
}


int Matrix::get_format(){
    return format;
}
int Matrix::get_cols() const{
    return this->cols;
    }
int Matrix::get_rows()const{
    return this->rows;
    }
void show_menu_format(){
cout<<"Откуда брать данные?\n"<<"1 - Из консоли\t\t2 - Из файла read.txt\n";
int a=0;
cin>>a; 
if ((a==1) || (a==2)){
    Matrix::format=a;
    return;}
else {
    do{
cout<<"Неверное значение, введите заново:\n";
cin>>a;
    }
while(a!=1 && a!=2);
Matrix::format=a;
}}
