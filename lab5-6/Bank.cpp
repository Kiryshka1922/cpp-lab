#include "Bank.h"
SavingAccount SaveAccounts [35];
int counter_save_acc=0;
DArray::~DArray(){
    std::fstream ofs ("Data_base.txt", std::ofstream::out | std::ofstream::trunc); 
    ofs.close();
        for (int t=0; t<length; t++){
            //cout<<"Я здесь";
            get_data()[t].add_in_base();
            if (get_data()[t].get_flag()==true){
                for (int i=0; i<counter_save_acc; i++){
                    if (SaveAccounts[i].get_ID()== get_data()[t].get_ID()){
                        SaveAccounts[i].add_in_base();
                    }
                }
                
            }
        }
    delete [] Users;
    }
void DArray::_resize_array(int size_new)
{
    if(size_new <= capacity)
        return;
 
    while(capacity < size_new) {
        capacity *= resize_factor;
        if(capacity >= max_length_array) {
            capacity = max_length_array;
            break;
        }
    }
 
    CheckingAccount* p = new CheckingAccount [capacity];
    for(int i = 0;i < length; ++i){
            p[i] = Users[i];
    } 
    delete [] Users;
    Users = p;
}
void DArray::push_back(CheckingAccount& other) 
{
    if (length==max_length_array){
        cout<<"База данных заполнена ";
        return;
    }
    if(length == capacity) {
        _resize_array(capacity * resize_factor);
    }
 
    if(length < capacity)
        Users[length++] = other;
}
int BankAccount::counter= 0;
void Transaction::push_in_base(int t){
    if (t==0){
    std::fstream ifs ("History_Operation.txt", std::ios::in | std::ios::out | std::ios::app);
    for (int r = get_counter_operation()-1; r>=0; r--){
        ifs<<get_ID()<<". ";
        ifs<<get_base_history()[r].where_from<<"---> "<<get_base_history()[r].Where<<get_base_history()[r].how_many<<";"<<"\n";
    }
    ifs.close();
    }
    else {
    // cout<<get_ID()<<". "<<get_Fname()<<" "<<get_Lname()<<"\n";
    if (get_counter_operation()==0){cout<<"У вас пока нет активных транзакций\n";}
    for (int r = get_counter_operation()-1; r>=0; r--){
        cout<<" "<<get_base_history()[r].where_from<<"---> "<<get_base_history()[r].Where<<get_base_history()[r].how_many;
        cout<<"\n";
        }}
}
void CheckingAccount::Reposit( CheckingAccount& people, int summa)  {
    if (summa>get_main_balance()){
        cout<<"У вас недостаточно средств для перевода";
        return;
    }
    this->get_base_history()[get_counter_operation()].where_from = "Основной счет "; 
    this->get_base_history()[get_counter_operation()].Where = people.get_Fname() +" " +  people.get_Lname()+" "; 
    this->get_base_history()[get_counter_operation()].how_many = summa;
    Main_Balance-=summa;
    counter_operation++;
    people.Deposit(*this, summa);
}
void CheckingAccount::Deposit(int summa)  {
    this->get_base_history()[get_counter_operation()].where_from = "Наличные "; 
    this->get_base_history()[get_counter_operation()].Where = "Основной счет "; 
    this->get_base_history()[get_counter_operation()].how_many = summa;
    counter_operation++;
    Main_Balance+=summa;
}
void CheckingAccount::Deposit (const CheckingAccount& people, int summa){
    Main_Balance+=summa;
    this->get_base_history()[get_counter_operation()].where_from =  people.get_Fname() +" " +people.get_Lname()+" "; 
    this->get_base_history()[get_counter_operation()].Where = "Основной счет "; 
    this->get_base_history()[get_counter_operation()].how_many = summa;
    counter_operation++;
}
void CheckingAccount::Reposit (int Summa)  {
    if (Summa>get_main_balance()){
        cout<<"К сожалению, на вашем счету чуть меньше денежных средств\n";
        return;
    }
    this->get_base_history()[get_counter_operation()].where_from = "Основной счет "; 
    this->get_base_history()[get_counter_operation()].Where = "Наличные "; 
    this->get_base_history()[get_counter_operation()].how_many = Summa;
    counter_operation++;
    Main_Balance-=Summa;
};
void CheckingAccount::Sreposit( SavingAccount& other, int summa)  {
   if (summa>get_main_balance()){
        cout<<"К сожалению, на вашем счету чуть меньше денежных средств\n";
        return;
    }
    this->get_base_history()[get_counter_operation()].where_from = "Основной счет "; 
    this->get_base_history()[get_counter_operation()].Where = "Сберегательный счет "; 
    this->get_base_history()[get_counter_operation()].how_many = summa;
    counter_operation++;
    cout<<"Перевод выполнен\n";
    Main_Balance-=summa; 
}
void CheckingAccount::add_in_base(){
    std::ofstream tfs("Data_base.txt", std::ios::app);
    tfs<<get_ID()<<". "<<get_Fname()<<" "<<get_Lname()<<" "<<get_main_balance()<<" "<<get_password()<<"\n";
    tfs.close();   
}
bool CheckingAccount::operator ==(SavingAccount& my_acc){
return my_acc.get_save_balanse()>=this->Main_Balance ? true : false;
}
void SavingAccount::Sdeposit(CheckingAccount& other, int summa)  {
      if (summa>Save_Balance){
        cout<<"К сожалению, на вашем сберегательном счету чуть меньше денежных средств\n";
        return;
    }
    other.get_base_history()[other.get_counter_operation()].where_from = "Cберегательный счет "; 
    other.get_base_history()[other.get_counter_operation()].Where = "Основной счет "; 
    other.get_base_history()[other.get_counter_operation()].how_many = summa;
    cout<<"Перевод выполнен\n";
    other.counter_operation++;
    Save_Balance-=summa;
    other.append_main_balance(summa);
    }
void SavingAccount::add_in_base(){
    std::ofstream tfs("Data_base.txt", std::ios::app);
    tfs<<"Saving account. "<<get_save_balanse()<<"\n";
    tfs.close();   
}
void show_menu(CheckingAccount& person, DArray& Users){
cout<<"Возможные опреации: \n\t 1 - Узнать баланс\n\t 2 - Пополнить баланс\n\t 3 - Снять наличные\n\t 4 - Перевести другому человеку\n\t 5 - Открыть сберегательный счет\n\t 6 - Перевести деньги на сберегательный счет\n\t 7 - Перевести со сберегательного счета на основной баланс \n\t 8 - Отобразить последние транзакции \n\t 9 - Сравнить основной счет и сберегательный \n\t 10 - Выйти из аккаунта\n";    
int do_it=0;
cin >> do_it;
while (do_it != 1 && do_it != 2 && do_it != 3 && do_it != 4 && do_it != 5 && do_it != 7 && do_it != 8 && do_it != 9 && do_it!=6 && do_it!=10)
{
    cout << "Неверное значение, введите заново:\n";
    cin >> do_it;
}
if (do_it==1){
    cout<<"1 - Баланс основного счета \t 2 - Баланс сберегательного счета\n";
    int f;
    cin >> f;
    while (f != 1 && f!=2)  
{
    cout << "Неверное значение, введите заново:\n";
    cin >> f;
}
if (f==1){
cout<<"Ваш баланс: "<<person.get_main_balance()<<"\n";
show_menu(person, Users);
}
if (f == 2){
    if (person.flag!=true){
        cout<<"На вашем аккаунте пока не открыт сберегательный счет\n";
        show_menu(person, Users);
        return;
        }
    else{
        for (int t=0; t<counter_save_acc; t++){
            if (SaveAccounts[t].get_ID()==person.get_ID())
             cout<<"Баланс сберегательного счета: "<<SaveAccounts[t].get_save_balanse()<<"\n";
        }
    } 
    // cout<<"Баланс сберегательного счета:"<<;
    show_menu(person, Users);    
}
}
if (do_it==2){
    cout<<"Введите сумму: ";
    int summ=0;
    cin>>summ;
    person.Deposit(summ);
    show_menu(person, Users);
}
if (do_it==3){
    cout<<"Какую суммы вы хотите получить наличными ?\n";
    int summa;
    cin>>summa;
    person.Reposit(summa);
    show_menu(person, Users);
    return;
}
if (do_it==4){
    cout<<"Введите ID того человека, которому хотите перевести: \t";
    int ID, Summa;
    cin>>ID;
    if (ID>Users.size() || ID<0){
    cout<<"Человека с таким ID, пока нет в нашем банке";
    show_menu(person, Users);
    return;}
    cout<<"Введите сумму :\t";
    cin>>Summa;
    person.Reposit(Users.get_data()[ID-1], Summa);
    show_menu(person, Users);
return;
}
if (do_it==5){
if (person.flag==false){
person.flag= true;
SaveAccounts[counter_save_acc++] = person;
cout<<"Сберегательный счет, был открыт удачно !\nТеперь вы можете переводить деньги на этот счет !\n";
}
else {
    cout<<"У вас уже есть активный сберегательный, счет. Проверьте его баланс.\n";
}
show_menu(person, Users);
return;
}
if (do_it==6){
    cout<<"Какую сумму перевести на сберегательный счет?\n";
    int summa;
    cin>>summa;
    for (int t=0; t<counter_save_acc; t++){
        if (SaveAccounts[t].get_ID()==person.get_ID()){
            person.Sreposit(SaveAccounts[t], summa);
            SaveAccounts[t].set_save_balance(summa);
            show_menu(person, Users);
            return;}       
    }
    cout<<"У вас пока нет сберегательного счета\n";
    show_menu(person, Users);
    return;
}
if (do_it==7){
    cout<<"Какую сумму перевести на основной счет?\n";
    int summa;
    cin>>summa;
    for (int t=0; t<counter_save_acc; t++){
        if (SaveAccounts[t].get_ID()==person.get_ID()){
            SaveAccounts[t].Sdeposit(person, summa);
            show_menu(person, Users);
            return;
        }
    }
    cout<<"У вас пока нет сберегательного счета\n";
    show_menu(person, Users);
    return;
}
if (do_it==8){
    cout<<"Последние транзакции в вашем аккаунте :\n";
    string filename = "History_Operation.txt";
    std::fstream file(filename, std::ios::in | std::ios::out );
    person.push_in_base(5);
    string str;
    string line [25];
    int length =0;
    string ID = std::to_string(person.get_ID());
    while(!file.eof()){
        file>>str;

        if (str==ID + "."){
            getline(file, line[length++],  ';');
            continue;
        }
        getline(file, str,  ';');
    }
    for (int t=length-1; t>=0; t--){
        cout<<line [t]<<"\n";
    }
    show_menu(person, Users);
    return;
}
if (do_it==9){
    for (int t=0; t<counter_save_acc; t++){
        if (SaveAccounts[t].get_ID()==person.get_ID()){
            if (person == SaveAccounts[t]){
                cout<<"На вашем сберегательном счете денег не меньше, чем на основном балансе\n";
            }
            else {
                cout<<"На вашем основном счете денег больше, чем на сберегательном счете\n";
            }
            show_menu(person, Users);
            return;}  
}
cout<<"У вас пока нет активного сберегательного счета!";
show_menu(person, Users);
return;
            }
if (do_it==10){
    show_menu_registration(Users);
    return;
}
}
void show_menu_registration( DArray&  Users){
    cout<<"\t\t*__MENU__*\n"<<"Выберите дейтвие :\n"<<"\t1 - Регистрация:\n\n"<<"\t2 - Войти : \n\n"<<"\t3 - Закрыть приложение :\n";
    int format;
    cin>>format;
    while (format!=1 && format !=2 && format!=3)
    {    
        cout<<"Неверное значение перечитайте, предложение выше!\n";
        cin>>format;
    }
    if (format==1){
        cout<<"Введите вашу фамилию: \t";
        string ln, fn, psw ,psw_2;
        cin>>ln;
        cout<<"\nВведите ваше имя : \t";
        cin>>fn;
        cout<<"\nВведите пароль : \t";
        cin>>psw;
        while (psw!=psw_2){
        cout<<"\nПовторите пароль : \t";
        cin>>psw_2;
        }
        //cout<<"Сколько денег положить основной счет (rub) ?";
        CheckingAccount user(ln, fn, psw);
        Users.push_back(user);
        //user.add_in_base();
        // Users.get_data()[user.get_ID()-1][0].
        cout<<"Вы успешно зарегистрировались!\n";
        show_menu(Users.get_data()[Users.size()-1], Users);
        show_menu_registration(Users);
        return;
    }
    if (format==3){
        return;
    }
    if (format==2){
        cout<<"Введите вашу фамилию: \t";
        string ln, fn, psw;
        cin>>ln;
        cout<<"\nВведите ваше имя : \t";
        cin>>fn;
        int numer=-1;
         for (size_t i=0; i<Users.size(); i++){
            //cout<<Users.get_data()[i].get_Fname()<<" "<<Users.get_data()[i].get_Lname()<<"\n";
            if (Users.get_data()[i].get_Fname()==ln && Users.get_data()[i].get_Lname()==fn){
                //cout<<"15689794";
                numer = i; 
                break;}
            if (i==(Users.size()-1) && numer==-1){
            cout<<"\nВы еще не зарегистрированы\n";
            show_menu_registration(Users);
            return;}
        }
        cout<<"\nВведите пароль : \t";
        cin>>psw;
        int chetch=0;
        while (psw!=Users.get_data()[numer].get_password() && chetch!=3){
        chetch++;
        cout<<"\nПовторите пароль : \t";
        cin>>psw;
        }
        if (chetch==3){
            cout<<"\nВы неверно ввели пароль 3 раза, попробуйте позже\n";
            show_menu_registration(Users);
            return;
        }
        show_menu(Users.get_data()[numer], Users);
        return;
    }

    return;
}
void Aktivate_Base(DArray& Users){
std::ifstream ofs ("Data_base.txt");
if (!ofs.is_open()){
cout<<"Файл не был открыт";
}
if (ofs.peek() == std::ifstream::traits_type::eof()){
    cout<<"База данных пуста";
    ofs.close();
    return;
    }

bool flag = true;
string str, Name, Famil, Passw, promech;
while (ofs.peek() != std::ifstream::traits_type::eof()){
    //cout<<"asdffgg";
if (flag==true){getline(ofs ,str, '.');}
int Balanc;
ofs>>Name>>Famil>>Balanc>>Passw;
CheckingAccount user (Name, Famil, Passw, Balanc);

ofs>>str;
flag = false;
if (str=="Saving"){
    flag==true;
    user.flag=true;
    getline (ofs, str, '.');
    //cout<<str<<"\n";
    int bal;
    ofs>>bal;
    //cout<<bal<<"\n";
    ofs>>str;
    SavingAccount r (user, bal);
    SaveAccounts[counter_save_acc++] = r;
    SaveAccounts[counter_save_acc-1].set_create_balance(bal);
}
Users.push_back(user);
}
ofs.close();
return;
}

