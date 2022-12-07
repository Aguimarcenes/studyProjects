#include <iostream>
#include <vector>
#include <locale.h>
#include <stdlib.h>

using namespace std;

class Conta {
    private:
    string nickname;
    string senhaUsuario;
    string emailUsuario;
    string planoUsuario;


    public:
    void setNickname(string nickname) {
        this->nickname = nickname;
    }

    void setSenha(string senhaUsuario){
        this->senhaUsuario = senhaUsuario;
    }

    void setEmail(string emailUsuario){
        this->emailUsuario = emailUsuario;
    }

    void setPlano(string planoUsuario){
        this->planoUsuario = planoUsuario;
    }

    string getNickname(){
        return this->nickname;
    }

    string getSenha(){
        return this->senhaUsuario;
    }

    string getEmail(){
        return this->emailUsuario;
    }

    string getPlano(){
        return this->planoUsuario;
    }

};

class planoPremium: public Conta{
    
};

class planoBasico: public Conta{

};

class Usuario {

    private:
    vector<string> favoritos;
    int tempoAssinatura;
    Conta conta;

    public:
    void setConta(Conta conta) {
        this->conta = conta;
    }

    Conta getConta() {
        return this->conta;
    }
};

class Menus {
    
    public:
    void menuPrincipal() {
        cout<<"     _____     _           ___ _ _     "<<endl;
        cout<<"    |  _  |___|_|_____ ___|  _| |_|_ _ "<<endl;
        cout<<"    |     |   | |     | -_|  _| | |_'_|"<<endl;
        cout<<"    |__|__|_|_|_|_|_|_|___|_| |_|_|_,_|"<<endl<<endl<<endl;

         
	    cout<<"              [1] Criar Conta"<<endl;
	    cout<<"              [2] Entrar"<<endl<<endl;
	    cout<<"                 Opcao: ";
    }

    void menuCriarConta(string *nickname, string *senhaUsuario, string *emailUsuario, int *opcaoPlano) {
        system("cls||clear");
        
        cout<<" =============== Criar Conta ==============="<<endl;
        cout<<" Nickname: ";
        cin>>*nickname;

        cout<<" Email: ";
        cin>>*emailUsuario;

        cout<<" Senha: ";
        cin>>*senhaUsuario;

        cout<<"                       \\     |     /  "<<endl;
        cout<<"       .  /\\             _________    "<<endl;
        cout<<"         /  \\         _ /_|_____|_\\ _ "<<endl;
        cout<<"        /   /           '. \\   / .'   "<<endl;
        cout<<"     .  \\  /   .          '.\\ /.'     "<<endl;
        cout<<"         \\/                 '.'       "<<endl<<endl;
        cout<<" [1] Plano Basico    [2] Plano Premium"<<endl<<endl;
	    cout<<"                Opcao: ";
        cin>>*opcaoPlano;
    }

    int menuEntrar(bool *usuarioValido, string *emailCriado, string *senhaCriada, vector <Usuario> bancoDeUsuarios) {
        int userAtual, i;
        system("cls||clear");
        while(*usuarioValido){
            cout<<" ================= Entrar =================="<<endl;

            cout << " Email: "; 
            cin>>*emailCriado;
            cout << " Senha: ";
            cin>>*senhaCriada;
            
            for(int i = 0; i < bancoDeUsuarios.size(); i++) {
                if(bancoDeUsuarios[i].getConta().getEmail() == *emailCriado && bancoDeUsuarios[i].getConta().getSenha() == *senhaCriada) {
                    *usuarioValido = false;
                    userAtual = i;
                    break;
                }
                else {
                    system("cls||clear");
                    cout<<endl<<"         Email e/ou senha incorretos!"<<endl; 
                }
            }
        } 
        system("cls||clear");
        cout<<endl;
        cout<<"         Login feito com sucesso!"<<endl;

        return userAtual;   
    }

    void telaDoUsuario(string nickname) {
        Menus menus;
        string input;
        int inputEntrar;


        cout<<"          Bem vindo, "<<nickname<<"!"<<endl; 
        cout<<"Digite a opção Deseja:";
        if (bancoDeUsuarios[userAtual].getPlano()) == "Plano Basico")
        {
            cout<<"[1] Assistir"<<endl;
            cout<<"[2] Favoritar"<<endl;
            cout<<"[3] Sair"<<endl;
            cin>>inputEntrar;
        }
        else
        {
            cout<<"[1] Assistir sem anuncios"<<endl;
            cout<<"[2] Favoritar"<<endl;
            cout<<"[3] Ler Mangas"<<endl;
            cout<<"[4] Sair"<<endl;
            cin>>inputEntrar;     
        }


};

int main(){

	vector<Usuario> bancoDeUsuarios;
	int entrada, opcaoPlano;
    string nickname, senhaUsuario, emailUsuario, planoUsuario;

    Conta planoBasico, planoPremium;
    Usuario usuario;
    Menus menus;

    while(true) {

        menus.menuPrincipal();
	    cin>>entrada;
    
	    switch(entrada) {
	    	case 1:

                menus.menuCriarConta(&nickname, &senhaUsuario, &emailUsuario, &opcaoPlano);

                if(opcaoPlano == 1) {
                    planoUsuario = "Plano Basico";

                    planoBasico.setNickname(nickname);
                    planoBasico.setSenha(senhaUsuario);
                    planoBasico.setEmail(emailUsuario);
                    planoBasico.setPlano(planoUsuario);

                    usuario.setConta(planoBasico);
                    bancoDeUsuarios.push_back(usuario);


                }
                if(opcaoPlano == 2) {
                    planoUsuario = "Plano Premium";

                    planoPremium.setNickname(nickname);
                    planoPremium.setSenha(senhaUsuario);
                    planoPremium.setEmail(emailUsuario);
                    planoPremium.setPlano(planoUsuario);

                    usuario.setConta(planoPremium);
                    bancoDeUsuarios.push_back(usuario);
                }

                system("cls||clear");
                cout<<endl;
                cout<<"         Conta criada com sucesso!"<<endl;

                break;

            case 2:
                string emailCriado, senhaCriada;
                bool usuarioValido = true;
                
                int userAtual = menus.menuEntrar(&usuarioValido, &emailCriado, &senhaCriada, bancoDeUsuarios);
                menus.telaDoUsuario(bancoDeUsuarios[userAtual].getConta().getNickname());

                break;
            
            
	    }
    }

	return 0;

}