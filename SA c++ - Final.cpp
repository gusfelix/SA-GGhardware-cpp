#include <iostream>
#include <locale.h>
#include <string.h>
#include <windows.h>

using namespace std;

int op0, op1, op2, op3, op4, op5, linha, categ;
string tipo, tipoM, senha, senhaU;

struct info{
	
	string nome, cpf, telefone, email, nasc, marca, site, cnpj, prod, forn;
	int disp, vend, cat;
	double preco;
};

info banco[5][1000];

//linha 0: hardwares e periféricos
//linha 2: clientes
//linha 3: fonecedores
//linha 4: parceiros

struct hist{
	string hora, data, cliente, produto;
};

hist compras[1000];


//todos os do while são usados para verificar se a opção escolhida é válida


//carregamento
void loading(){
	
	for(int t = 0; t <= 100; t = t + 2){
		
		cout << t << "%";
		system("cls");
	}
}


//boas vindas
void bemvindo(){
	
	system("cls");
                                                                 
	loading();
	
	cout << "Seja bem-vindo ao programa de gerenciamento da GGHARDWARE \n\n";
	cout << "Esse programa funciona por meios de tópicos \n";
	cout << "Para acessar uma opção basta digitar o número que está dentro dos [ ] e pressionar enter \n\n";
	
	Sleep(3000);
	system("pause");
}


//login
void login(){
	
	senha = "1234adm";
	
	cout << "Usuário: ADMINISTRADOR\n";
	cout << "Senha: ";
	cin >> senhaU;
	cin.sync();
	
	while(senhaU != senha){
		
		system("cls");
		
		cout << "Usuário: ADMINISTRADOR\n";
		cout << "Senha incorreta. Digite novamente: ";
		cin >> senhaU;
		cin.sync();
	}
		cout << "\nLogin efetuado! \n";
		system("pause");
}


//menu principal
void menu_principal(){
	
	system("cls");
	
	do{
		cout << "MENU PRINCIPAL \n \n";
		cout << "[1] Produtos \n";
		cout << "[2] Clientes \n";
		cout << "[3] Fornecedores \n";
		cout << "[4] Parceiros \n";
		cout << "[5] Ajuda \n";
		cout << "[6] Sobre \n";
		cout << "[7] Logoff";
		cout << "\nQual opção deseja acessar? \n=> ";
		cin >> op1;
		cin.sync();
		
		system("cls");
	
	}while(op1 > 7 or op1 < 1);	
}


//sub menu
void subMenu(){
	
	//system("cls");
	
	cout << tipoM << "\n \n"; 
	
	do{
		cout << "[1] Listar todos \n";
		cout << "[2] Pesquisar \n";
		cout << "[3] Cadastrar novo \n";
		cout << "[4] Atualizar \n";
		cout << "[5] Excluir \n";
		if(linha == 0 or linha == 1){
			cout << "[6] Listar por categorias \n";
			
		}else if(linha == 2){
			cout << "[6] Histórico de compras \n";
		}
		cout << "[0] Retornar \n";
		cout << "\nQual opção deseja acessar? \n=> ";
		cin >> op2;
		cin.sync();
		
		system("cls");
	
	}while(op2 > 6 or op2 < 0);	
}


//categorias dos produtos
void menu_categ(){
	
	cout << "CATEGORIAS: \n\n";
	cout << "[1] Processadores \n";
	cout << "[2] Placas de video \n";
	cout << "[3] Placas mãe \n";
	cout << "[4] Memórias Ram \n";
	cout << "[5] Fontes \n";
	cout << "[6] HDs/SSDs \n";
	cout << "[7] Teclados \n";
	cout << "[8] Mouses \n";
	cout << "[9] Fones \n";
	cout << "[10] Monitores \n";
	cout << "[0] Voltar\n";
	cout << "\nQual opção deseja acessar? \n=> ";
	cin >> op4;
	cin.sync();
}


//ficha genérica pra qualquer informação
int ficha(int lin, int col){
	
	cout << "\n==============> Dados "<< tipo <<" <==============\n";
	
	cout << "\nCódigo: " << col;
	cout << "\n[1] Nome: " << banco[lin][col].nome;
	
	if(lin == 0 or lin == 1){  //dados dos produtos
		
		cout << "\n[2] Marca: " << banco[lin][col].marca;
		cout << "\n[3] Preço: R$ ";
		printf("%.2f", banco[lin][col].preco);
		
		cout << "\n[4] Site: " << banco[lin][col].site;
		cout << "\n[5] Forcedor: " << banco[lin][col].forn;
		cout << "\n[6] Vendidos: " << banco[lin][col].vend;
		cout << "\n[7] Disponível: " << banco[lin][col].disp;
		cout << "\n[8] Total das vendas: R$ ";
		printf("%.2f", banco[lin][col].vend * banco[lin][col].preco);
	
	}else if(lin == 2){  //dados dos clientes
	
		cout << "\n[2] CPF: " << banco[lin][col].cpf;
		cout << "\n[3] E-mail: " << banco[lin][col].email;
		cout << "\n[4] Telefone: " << banco[lin][col].telefone;
		cout << "\n[5] Data de nascimento: " << banco[lin][col].nasc;
		
	}else if(lin == 3){  //dados dos fornecedores
		
		cout << "\n[3] CNPJ: " << banco[lin][col].cnpj;
		cout << "\n[3] E-mail: " << banco[lin][col].email;
		cout << "\n[4] Telefone: " << banco[lin][col].telefone;
		cout << "\n[5] Produtos fornecidos: " << banco[lin][col].prod;
		
		if(op2 == 1 or op2 == 2){
			
			cout << "\n[5] Produtos fornecidos: \n\n";
			
			for(int i = 0; i < 1000; i++){
				
				if(banco[0][i].forn == banco[lin][col].nome){
					
					cout << "> " << banco[0][i].nome << endl;
				}	
			}
		}
		
	}else if(lin == 4){  //dados dos parceiros
		
		cout << "\n[2] CNPJ: " << banco[lin][col].cnpj;
		cout << "\n[3] E-mail: " << banco[lin][col].email;
		cout << "\n[4] Telefone: " << banco[lin][col].telefone;
		
		if(op2 == 1 or op2 == 2){
			
			cout << "\n[5] Produtos anunciados: \n\n";
			
			for(int i = 0; i < 1000; i++){
				
				if(banco[0][i].site == banco[lin][col].nome){
					
					cout << "> " << banco[0][i].nome << endl;
				}	
			}
		}
	}

	cout << "\n\n=============================================\n";
}


//listar por categoria
int setor(int lin){
	
	for(int col = 0; col < 1000; col++){
		
		if(banco[lin][col].nome != " " and banco[lin][col].cat == op4){
			
			ficha(lin, col);
		}
	}
	do{
		cout << "\n1. Voltar \n2. Menu principal \n=> ";
		cin >> op3;
	
	}while(op3 != 1 and op3 != 2 );
	
	switch(op3){
		
		case 2:
			menu_principal();
			break;
	}
}


//listar
int listar(int lin){
	
	for(int col = 0; col < 1000; col++){
		
		if(banco[lin][col].nome != " "){
			
			ficha(lin, col);
		}
	}
	do{
		cout << "\n1. Voltar \n2. Menu principal \n=> ";
		cin >> op3;
	
	}while(op3 != 1 and op3 != 2 );
	
	switch(op3){
			
		case 2:
			menu_principal();
			break;
	}
}


//pesquisar
int pesquisar(int lin){
	
	int cod;
	
	cout << "\nInforme o código do "<< tipo <<" que deseja pesquisar (-1 para retornar): ";
	cin >> cod;
	cin.sync();
	
	if(cod == -1){
		
		return 0;
	}
	
	for(int col = 0; col < 1000; col++){
		
		if(cod == col){
			
			if(banco[lin][col].nome == " "){
		
				cout << "\nCódigo não encontrado! \n";
				break;
			}
			
			ficha(lin, col);
		}
	}
	
	do{
		cout << "\n1. Voltar \n2. Pesquisar outro "<< tipo <<"\n3. Menu principal \n=> ";
		cin >> op3;
		
	}while(op3 > 3 and op3 < 1);
	
	
	switch(op3){
			
		case 2:
			pesquisar(linha);
			break;
		
		case 3:
			menu_principal();
			break;
	}
}


//cadastrar
int cadastrar(int lin){
	
	int cod;
	
	for(int col = 0; col < 1000; col++){
		
		if(banco[lin][col].nome == " "){
			
			cout << "\n============== "<< tipo << " cod. " << col <<" ==============\n" ;
			
			cout <<"Nome: ";
			getline(cin, banco[lin][col].nome);
			
			if(lin == 0 or lin == 1){  //dados dos produtos
		
				cout << "\nMarca: ";
				getline(cin, banco[lin][col].marca);
				
				cout << "\nPreço: R$ ";
				cin >> banco[lin][col].preco;
				cin.sync();
				
				cout << "\nCódigo do site onde é vendido: "; 
				cin >> cod;
				
				banco[lin][col].site = banco[4][cod].nome;
				
				cout << "\nCódigo do fornecedor: "; 
				cin >> cod; 
				cin.sync();
				
				banco[lin][col].forn = banco[3][cod].nome;
			
				
				cout << "\nVendidos: ";
				cin >> banco[lin][col].vend;
				cin.sync();
				
				cout << "\nDisponível: ";
				cin >> banco[lin][col].disp;
				cin.sync();
				
				cout << "\nCatergoria: \n";
				cout << "\n1. Processador \n";
				cout << "2. Placa de video \n";
				cout << "3. Placa mãe \n";
				cout << "4. Memória Ram \n";
				cout << "5. Fonte \n";
				cout << "6. HD/SSD \n";
				cout << "7. Teclado \n";
				cout << "8. Mouse \n";
				cout << "9. Fone \n";
				cout << "10. Monitor \n";
				cout << "=> ";
				cin >> banco[lin][col].cat;
				cin.sync();
			
			}else if(lin == 2){  //dados dos clientes
			
				cout << "\nCPF: ";
				getline(cin, banco[lin][col].cpf);
				
				cout << "\nE-mail: "; 
				getline(cin, banco[lin][col].email);
				
				cout << "\nTelefone: "; 
				getline(cin, banco[lin][col].telefone);
				
				cout << "\nData de nascimento: "; 
				getline(cin, banco[lin][col].nasc);
				
			}else if(lin == 3){  //dados dos fornecedores
				
				cout << "\nCNPJ: "; 
				getline(cin, banco[lin][col].cnpj);
				
				cout << "\nE-mail: ";
				getline(cin, banco[lin][col].email);
				
				cout << "\nTelefone: ";
				getline(cin, banco[lin][col].telefone);
			
				
			}else if(lin == 4){  //dados dos parceiros
				
				cout << "\nCNPJ: ";
				getline(cin, banco[lin][col].cnpj);
				
				cout << "\nE-mail: ";
				getline(cin, banco[lin][col].email);
				
				cout << "\nTelefone: ";
				getline(cin, banco[lin][col].telefone);
			}
			
			break;
		}
	}
	
	cout << "\n" << tipo << " cadastrado com sucesso!\n";
	
	do{
		cout << "\n1. Voltar \n2. Cadastrar outro "<< tipo <<"\n3. Menu principal \n=> ";
		cin >> op3;
		
	}while(op3 > 3 or op3 < 1);
	
	
	switch(op3){
		
		case 2:
			cadastrar(linha);
			break;
		
		case 3:
			menu_principal();
			break;
	}
	
}


//atualizar
int atualizar(int lin){
	
	int cod, mod, cd;
	
	system("cls");
	
	cout << "ATUALIZAR \n";
	
	cout << "\nInforme o código do "<< tipo <<" que deseja atualizar (-1 para retornar): ";
	cin >> cod;
	cin.sync();
	
	if(cod == -1){
		
		return 0;
	}
	
	for(int col = 0; col < 1000; col++){
		
		if(cod == col){
			
			if(banco[lin][col].nome == " "){
		
				cout << "\nCódigo não encontrado!\n";
				break;
			}
			
			ficha(lin, col);
			
			cout << "Qual informação deseja alterar? \n=> ";
			cin >> mod;
			cin.sync();
			
			
			cout << "Alterar ";
			
			switch(mod){
				
				case 1:  //alterar o nome
					
					cout << "nome: ";
					getline(cin, banco[lin][col].nome);
					
					break;
					
				case 2:  //alterar a marca, o cpf ou o cnpj
					
					if(lin == 0 or lin == 1){
						cout << "marca: ";
						getline(cin, banco[lin][col].marca);
					
					}else if(lin == 2){
						cout << "CPF (xxx.xxx.xxx-xx): ";
						getline(cin, banco[lin][col].cpf);
					
					}else if(lin == 3 or lin == 4){
						cout << "CNPJ: ";
						getline(cin, banco[lin][col].cnpj);
					}	
					break;
					
				case 3:  //alterar o preço ou o email
					
					if(lin == 0 or lin == 1){
						cout << "preço: ";
						cin >> banco[lin][col].preco;
						cin.sync();
					
					}else if(lin == 2 or lin == 3 or lin == 4){
						cout << "e-mail: ";
						getline(cin, banco[lin][col].email);
					}
					break;
				
				case 4:  //alterar site ou telefone
					
					if(lin == 0 or lin == 1){
						cout << "site. Código do site: ";
						cin >> cd;
						cin.sync();
						
						banco[lin][col].site = banco[4][cd].nome;
						
					}else if(lin == 2 or lin == 3 or lin == 4){
						cout << "telefone ((xx)9 xxxx-xxxx): ";
						getline(cin, banco[lin][col].telefone);
					}
					break;
					
				case 5:  //alterar o fornecedor, a data de nascimento ou o produto fornecido
					
					if(lin == 0 or lin == 1){
						cout << "fornecedor. Código do fornecedor: ";
						cin >> cd;
						cin.sync();
						
						banco[lin][col].forn = banco[3][cd].nome;
						
					}else if(lin == 2){
						cout << "data de nascimento(dd/mm/aaaa): ";
						getline(cin, banco[lin][col].nasc);
					
					}else if(lin == 3){
						cout << "produtos fornecidos: ";
						getline(cin, banco[lin][col].prod);
					}
					break;
				
				case 6: //alterar a quantidade de vendidos
					
					if(lin == 0 or lin == 1){
						cout << "total vendido: ";
						cin >> banco[lin][col].vend;
						cin.sync();
					}
					
					break;
				
				case 7: //alterar quantidade disponível
					
					if(lin == 0 or lin == 1){
						cout << "total disponível: ";
						cin >> banco[lin][col].disp;
						cin.sync();
					}
					
					break;
			}
		}
	}
	
	cout << "\n" << tipo << " atualizado com sucesso!\n";
	
	do{
		cout << "\n1. Voltar \n2. Atualizar outro "<< tipo <<"\n3. Menu principal \n=> ";
		cin >> op3;
		
	}while(op3 > 3 or op3 < 1);
	
	
	switch(op3){
		
		case 2:
			atualizar(linha);
			break;
		
		case 3:
			menu_principal();
			break;
	}
}


//excluir
int excluir(int lin){
	
	int cod, exc;
	
	cout << "Código do "<< tipo <<" para excluir (-1 para retornar): ";
	cin >> cod;
	cin.sync();
	
	if(cod == -1){
		
		return 0;
	}
	
	for(int col = 0; col < 1000; col++){
		
		if(col == cod){
			
			if(banco[lin][col].nome == " "){
		
				cout << "\nCódigo não encontrado! \n";
				break;
			}
		
			ficha(lin, col);
			do{
				cout << "Deseja excluir esse? "<< tipo <<" \n0. Não 1. Sim \n=>";
				cin >> exc;
				cin.sync();
				
			}while(exc > 1 or exc < 0);
			
			
			if(exc == 1){
				
				banco[lin][col].nome = " ";
				
				
			}else if(exc == 0){
				
				return 0;
			}
		}
	}
	
	cout << "\n" << tipo << " excluído com sucesso!\n";
	
	do{
		cout << "\n1. Voltar \n2. Excluir outro "<< tipo <<"\n3. Menu principal \n=> ";
		cin >> op3;
		cin.sync();
		
	}while(op3 > 3 and op3 < 1);
	 
	switch(op3){
		
		case 2:
			excluir(linha);
			break;
		
		case 3:
			menu_principal();
			break;
	}
}


//cadastrar nova compra
void novaCompra(){
	
	int x;
	
	system("cls");
	
	for(int i = 0; i < 1000; i++){
		
		if(compras[i].cliente == " "){
			
			cout << "==========> Adicionar nova compra <==========\n\n";
			
			cout << "Código do cliente: ";
			cin >> x;
			cin.sync();
			
			compras[i].cliente = banco[2][x].nome;
			
			cout << "Código do produto: ";
			cin >> x;
			cin.sync();
			
			compras[i].produto = banco[0][x].nome;
			
			banco[0][x].disp--;
			banco[0][x].vend++;
			
			
			cout << "Data da compra: ";
			getline(cin, compras[i].data);
			
			cout << "Hora da compra: ";
			getline(cin, compras[i].hora);
			
			cout << "\nCompra cadastrada com sucesso!\n";
			system("pause");
			
			
			break;
		}
	}
}


//histórico de compras
void hist_compras(){
	
	for(int i = 0; i < 1000; i++){
		
		if(compras[i].cliente != " "){
			
			cout << "\n==============> Compra nº "<< i <<"<==============\n";
			cout << "\nNome do cliente: " << compras[i].cliente;
			cout << "\nProduto comprado: " << compras[i].produto;
			cout << "\nData da compra: " << compras[i].data;
			cout << "\nHora da compra: " << compras[i].hora;
			cout << "\n===========================================\n";
		}
	}
	
	cout << "1. Voltar \n2. Cadastrar nova compra \n=> ";
	cin >> op5;
	cin.sync();
	
	if(op5 == 2){
		
		novaCompra();
	}
}


//opções do sub menu
void opcoes(){
	
	
	switch(op2){
		
		case 1:
			
			listar(linha);
			break;
		
		case 2:
			
			pesquisar(linha);
			break;
			
		case 3:
			
			cadastrar(linha);
			break;
			
		case 4:
			
			atualizar(linha);
			break;
			
		case 5:
			
			excluir(linha);
			break;
			
		case 6:
			
			if(linha == 0 or linha == 1){
				
				menu_categ();
				setor(linha);
					
			}else if(linha == 2){
				
				hist_compras();
			}
			
			break;
		
		case 0:
			menu_principal();
			break;
	}
}


//INÍCIO DO PROGRAMA!!!
int main(int argc, char** argv) {

    setlocale(LC_ALL, "Portuguese");
    
    
    //definindo todos os nome como " "
    for(int l = 0; l < 5;l++){
    	
    	for(int c = 0; c < 1000; c++){
    		
    		banco[l][c].nome = " ";
    		banco[l][c].site = " ";
    		compras[c].cliente = " ";
		}
	}
    
    
    //"BANCO DE DADOS"
    
    //hardwares e periféricos
    banco[0][0].nome = "AMD Ryzen 3 3300X";        banco[0][0].marca = "AMD";       banco[0][0].preco = 999.03;   banco[0][0].site = "Mercado Livre"; banco[0][0].forn = "GPJ";  banco[0][0].disp = 96;  banco[0][0].vend = 14;  banco[0][0].cat = 1;
    banco[0][1].nome = "Core I5-10400 4.30GHz";    banco[0][1].marca = "Intel";     banco[0][1].preco = 899.90;   banco[0][1].site = "Mercado Livre"; banco[0][1].forn = "GPJ";  banco[0][1].disp = 51;  banco[0][1].vend = 13;  banco[0][1].cat = 1;
    banco[0][2].nome = "Radeon RX 550 4GB";        banco[0][2].marca = "AMD";       banco[0][2].preco = 899.00;   banco[0][2].site = "Mercado Livre"; banco[0][2].forn = "GPJ";  banco[0][2].disp = 11;  banco[0][2].vend = 4;   banco[0][2].cat = 2;
    banco[0][3].nome = "GTX 1050 Ti 4GB 128Bit";   banco[0][3].marca = "NVIDIA";    banco[0][3].preco = 1599.99;  banco[0][3].site = "Mercado Livre"; banco[0][3].forn = "GPJ";  banco[0][3].disp = 20;  banco[0][3].vend = 7;   banco[0][3].cat = 2;
    banco[0][4].nome = "Placa-Mãe A320M-K/BR AMD"; banco[0][4].marca = "Asus";      banco[0][4].preco = 359.90;   banco[0][4].site = "Mercado Livre"; banco[0][4].forn = "GPJ";  banco[0][4].disp = 18;  banco[0][4].vend = 20;  banco[0][4].cat = 3;
    banco[0][5].nome = "Placa-Mãe A320M-K/BR Intel";banco[0][5].marca = "Asus";     banco[0][5].preco = 439.90;   banco[0][5].site = "Mercado Livre"; banco[0][5].forn = "GPJ";  banco[0][5].disp = 12;  banco[0][5].vend = 25;  banco[0][5].cat = 3;
    banco[0][6].nome = "Mem DDR4 8GB 3000MHz";     banco[0][6].marca = "Geil";      banco[0][6].preco = 219.00;   banco[0][6].site = "Mercado Livre"; banco[0][6].forn = "GPJ";  banco[0][6].disp = 30;  banco[0][6].vend = 10;  banco[0][6].cat = 4;
    banco[0][7].nome = "Mem 8GB 3000Mhz DDR4";     banco[0][7].marca = "Kingston";  banco[0][7].preco = 279.00;   banco[0][7].site = "Mercado Livre"; banco[0][7].forn = "GPJ";  banco[0][7].disp = 27;  banco[0][7].vend = 15;  banco[0][7].cat = 4;
    banco[0][8].nome = "Fonte 550W GP-P550";       banco[0][8].marca = "Gigabyte";  banco[0][8].preco = 389.00;   banco[0][8].site = "Mercado Livre"; banco[0][8].forn = "GPJ";  banco[0][8].disp = 5;   banco[0][8].vend = 23;  banco[0][8].cat = 5;
    banco[0][9].nome = "Fonte 500W GC-PS001";      banco[0][9].marca = "Redragon";  banco[0][9].preco = 279.00;   banco[0][9].site = "Mercado Livre"; banco[0][9].forn = "GPJ";  banco[0][9].disp = 7;   banco[0][9].vend = 12;  banco[0][9].cat = 5;
    banco[0][10].nome = "HD 2TB 3.5´ SATA III";    banco[0][10].marca = "Seagate";  banco[0][10].preco = 400;     banco[0][10].site = "Mercado Livre";banco[0][10].forn = "GPJ"; banco[0][10].disp = 30; banco[0][10].vend = 19; banco[0][10].cat = 6;
    banco[0][11].nome = "SSD 480GB";               banco[0][11].marca = "Kingston"; banco[0][11].preco = 329.99;  banco[0][11].site = "Mercado Livre";banco[0][11].forn = "GPJ"; banco[0][11].disp = 35; banco[0][11].vend = 24; banco[0][11].cat = 6;
	banco[0][12].nome = "Teclado Gamer Alloy RGB"; banco[0][12].marca = "HyperX";   banco[0][12].preco = 279.91;  banco[0][12].site = "Mercado Livre";banco[0][12].forn = "GPJ"; banco[0][12].disp = 32; banco[0][12].vend = 10; banco[0][12].cat = 7;
    banco[0][13].nome = "Teclado Mecânico K552";   banco[0][13].marca = "Redragon"; banco[0][13].preco = 319.99;  banco[0][13].site = "Mercado Livre";banco[0][13].forn = "GPJ"; banco[0][13].disp = 24; banco[0][13].vend = 15; banco[0][13].cat = 7;
    banco[0][14].nome = "Mouse Gamer G502 HERO";   banco[0][14].marca = "Logitech"; banco[0][14].preco = 299.90;  banco[0][14].site = "Mercado Livre";banco[0][14].forn = "GPJ"; banco[0][14].disp = 15; banco[0][14].vend = 25; banco[0][14].cat = 8;
    banco[0][15].nome = "MOUSE GAMER G403 HERO";   banco[0][15].marca = "Logitech"; banco[0][15].preco = 229.90;  banco[0][15].site = "Mercado Livre";banco[0][15].forn = "GPJ"; banco[0][15].disp = 18; banco[0][15].vend = 19; banco[0][15].cat = 8;
    banco[0][16].nome = "Fone Quantum 50 Preto";   banco[0][16].marca = "JBL";      banco[0][16].preco = 157.00;  banco[0][16].site = "Mercado Livre";banco[0][16].forn = "GPJ"; banco[0][16].disp = 36; banco[0][16].vend = 20; banco[0][16].cat = 9;
    banco[0][17].nome = "Headset Cloud Stinger";   banco[0][17].marca = "HyperX";   banco[0][17].preco = 309.00;  banco[0][17].site = "Mercado Livre";banco[0][17].forn = "GPJ"; banco[0][17].disp = 22; banco[0][17].vend = 16; banco[0][17].cat = 9;
    banco[0][18].nome = "Monitor Widescreen 21,5”";banco[0][18].marca = "LG";       banco[0][18].preco = 1010.90; banco[0][18].site = "Mercado Livre";banco[0][18].forn = "GPJ"; banco[0][18].disp = 11; banco[0][18].vend = 10; banco[0][18].cat = 10;
    banco[0][19].nome = "Monitor Gamer LG 24”";    banco[0][19].marca = "LG";       banco[0][19].preco = 1086.10; banco[0][19].site = "Mercado Livre";banco[0][19].forn = "GPJ"; banco[0][19].disp = 9;  banco[0][19].vend = 12; banco[0][19].cat = 10;
    
	
	//clientes
	banco[2][0].nome = "Lucas Vicente Araújo";    banco[2][0].cpf = "938.062.905-20";  banco[2][0].email = "nicolasvicente@mucoucah.com.br";   banco[2][0].telefone = "(86) 99465-0354";	banco[2][0].nasc = "19/04/1980";
	banco[2][1].nome = "Raul Renan Iago Souza";	  banco[2][1].cpf = "947.442.277-08";  banco[2][1].email = "raulrenansouza@sandvik.com";	   banco[2][1].telefone = "(86) 98563-3863";	banco[2][1].nasc = "09/03/1998";	
	banco[2][2].nome = "Juan Iago Almeida";	      banco[2][2].cpf = "254.189.673-55";  banco[2][2].email = "juan.iago.almeida@paae.com.br";    banco[2][2].telefone = "(91) 99730-8709";	banco[2][2].nasc = "14/02/1990";	
	banco[2][3].nome = "Bernardo Cauê Martins";   banco[2][3].cpf = "881.487.968-07";  banco[2][3].email = "bernardomartins@tecsysbrasil.com"; banco[2][3].telefone = "(27) 99861-0437";	banco[2][3].nasc = "01/01/1988";	
	banco[2][4].nome = "Liz Elaine Cavalcanti";	  banco[2][4].cpf = "205.483.956-67";  banco[2][4].email = "liz_cavalcanti@engeco.com.br";	   banco[2][4].telefone = "(96) 99951-0074";	banco[2][4].nasc = "08/01/1994";	
	banco[2][5].nome = "Natália Larissa Lopes";	  banco[2][5].cpf = "027.599.610-79";  banco[2][5].email = "natalia-lopes76@sabesp.com.br";	   banco[2][5].telefone = "(85) 98227-0547";	banco[2][5].nasc = "12/03/1985";	
	banco[2][6].nome = "Luiza Silva Brito";	      banco[2][6].cpf = "568.175.482-09";  banco[2][6].email = "luzia_brito@lhp.com.br";           banco[2][6].telefone = "(96) 98196-2099";	banco[2][6].nasc = "14/02/2001";
	banco[2][7].nome = "Edson Thiago Gomes";      banco[2][7].cpf = "963.958.042-27";  banco[2][7].email = "edsongomes@siexpress.com.br";	   banco[2][7].telefone = "(61) 98952-8160";	banco[2][7].nasc = "07/02/1990";	
	banco[2][8].nome = "Manoel Kevin Silveira";	  banco[2][8].cpf = "104.131.977-00";  banco[2][8].email = "manoel_silveira@mailinator.com";   banco[2][8].telefone = "(47) 98585-1845";	banco[2][8].nasc = "15/01/1995";	
	banco[2][9].nome = "Nelson Henrique Rezende"; banco[2][9].cpf = "828.807.182-10";  banco[2][9].email = "nelsonrezende96@beminvestir.com";  banco[2][9].telefone = "(61) 99747-3449";	banco[2][9].nasc = "10/03/1983";		
	
	
	//fornecedores
	banco[3][0].nome = "GPJ"; banco[3][0].telefone = "(31) 2519-0401";  banco[3][0].email = "gpj@contato.com.br";  banco[3][0].cnpj = "06.697.988/0001-76";
	
	
	//parceiros
	banco[4][0].nome = "Mercado Livre";  banco[4][0].telefone = "0800-637-7246";  banco[4][0].email = "mercadolivre@contato.com.br";  banco[4][0].cnpj = "03.499.243/0001-04";
	
	//histórico de compras
	compras[0].cliente = banco[2][0].nome; compras[0].data = "28/04/2022"; compras[0].hora = "12:43"; compras[0].produto = banco[0][6].nome;
	compras[1].cliente = banco[2][0].nome; compras[1].data = "28/04/2022"; compras[1].hora = "11:48"; compras[1].produto = banco[0][11].nome;
	compras[2].cliente = banco[2][2].nome; compras[2].data = "28/04/2022"; compras[2].hora = "15:21"; compras[2].produto = banco[0][1].nome;
	compras[3].cliente = banco[2][3].nome; compras[3].data = "28/04/2022"; compras[3].hora = "09:35"; compras[3].produto = banco[0][1].nome;
	compras[4].cliente = banco[2][8].nome; compras[4].data = "28/04/2022"; compras[4].hora = "17:33"; compras[4].produto = banco[0][3].nome;
	
	while(op0 != 2){
		
		
		
		cout << "O que deseja fazer? \n1. Fazer Login \n2. Encerrar o programa \n=> ";
		cin >> op0;
		cin.sync();
		
		system("cls");
		
		if(op0 == 1){
			
			login();
			bemvindo();
	
		}else if(op0 == 2){
			
			break;
		}
		
	
	
		menu_principal();
		
		while(op1 != 7){
			
			
			system("cls");
			
			switch(op1){
			
			case 1:  //produtos
				
				linha = 0;
				
				tipo = "produto";
				tipoM = "PRODUTOS";
				
				subMenu();
				opcoes();
	
				break;
			
			case 2:  //clientes
				
				linha = 2;
				
				tipo = "cliente";
				tipoM = "CLIENTES";
				
				subMenu();
				opcoes();
				break;
			
			case 3:  //fornecedores
				
				linha = 3;
				
				tipo = "fornecedor";
				tipoM = "FORNECEDORES";
				
				subMenu();
				opcoes();
				break;
			
			case 4:  //parceiros
				
				linha = 4;
				
				tipo = "parceiro";
				tipoM = "PARCEIROS";
				
				subMenu();
				opcoes();
				break;
			
			case 5:  //ajuda
				
				cout << "AJUDA";
				cout<<""<<endl;
				cout<<"O sistema funciona por meio de tópicos, então você sempre deverá selecionar o número correspondente para a opção que deseja selecionar, exceto aonde se deve inserir texto."<<endl;
				cout<<"Todos os menus apresentam a opção para retornar para a opção anterior."<<endl;
				cout<<""<<endl;
				cout<<"No Menu Principal você tem ao seu alcance:"<<endl;
				cout<<"As opções de um à quatro em que você irá obter algumas opções como: "<<endl;
				cout<<"Produtos."<<endl;
				cout<<"Clientes."<<endl;
				cout<<"Fornecedores."<<endl;
				cout<<"Parceiros."<<endl;
				cout<<"Excluir."<<endl;
				cout<<"Por algum produto, cliente, fornecedor ou parceiro do seu banco de dados."<<endl;
				cout<<"A quinta opção na qual é a que você se encontra é um guia básico para a utilização do programa."<<endl;
				cout<<"A sexta opção é apenas um menu dedicado aos desenvolvedores deste projeto e contém algumas informações para o contato com eles se necessário."<<endl;
				cout<<"E a sétima opção é a para você encerrar o programa."<<endl;
				cout<<""<<endl;
				cout<<"Nos Submenus:"<<endl;
				cout<<"Ao selecionar a opção de listar irá aparecer todas as fichas com os dados já listados por você daquele menu selecionado anteriormente."<<endl;
				cout<<"Já na de pesquisar você pode pesquisar por uma ficha utilizando os números de um a quatro para respectivamente:"<<endl;
				cout<<"1. Por dados de Clientes."<<endl;
				cout<<"2. Por dados de Produtos."<<endl;
				cout<<"3. Por dados de Fornecedores."<<endl;
				cout<<"4. Por dados de Parceiros."<<endl;
				cout<<"E de um a mil para a númeração da ficha."<<endl;
				cout<<""<<endl;
				cout<<"A opção cadastrar você vai ser encaminhado para uma ficha vazia aonde irá preenche-lá com os dados da opção selecionada anteriormente."<<endl;
				cout<<"A opção atualizar é feita para você poder atualizar os dados de um produto, cliente , fornecedor ou parceiro."<<endl;
				cout<<"Enquanto a opção de excluir é para você poder apagar por completo os dados de um produto, cliente , fornecedor ou parceiro."<<endl;
				cout<<"Submenus exclusivos:"<<endl;
				cout<<""<<endl;
				cout<<"Aonde você encontra o menu de produtos é possivel por uma sexta opção você listar os produtos pelas suas categorias."<<endl;
				cout<<""<<endl;
				system("pause");
				
				menu_principal();
	
				break;
			
			case 6: //sobre
				
				cout << "SOBRE\n";
				cout<<""<<endl;
				cout<<"Software desenvolvido por: "<<endl;
				cout<<"Gustavo Felix."<<endl;
				cout<<"Marcos Gustavo."<<endl;
				cout<<"Ronald Henrique."<<endl;
				cout<<"Clóvis Domingues."<<endl;
				cout<<endl;
				cout<<"Versão: Beta 0.05"<<endl;
				cout<<"Contatos: "<<endl<<"Telefone:(31) 99123-5678"<<endl;
				cout<<"E-mail:CGMR.net@gmail.com"<<endl;
				system("pause");
				
				menu_principal();
				
				break;
			
			case 7:
				
				"Logoff";
				break;
				
			}
		}
	}
	
	loading();
	
	cout << "Programa encerrado";
	
	
    cout << "\n \n";
    system("pause");

    return 0;
}

