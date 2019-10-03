#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <list>
#include <fstream>//импортирам fstream за работа със файл
#include <vector>
#include <sstream>//импортитам sstream ,за обработрка на данните от файла

using namespace std;
 
class CPlane{//Създавам класът CPlane
		string planeModel;//модел на самолета
		int flightTime;//брой литателни часове
	public:
	//Constreuctors
		CPlane(); //Дефалтен конструктор.

		CPlane(string PM, int FT) {	//Експлицитен конструктор, приемащ аргументи за променливите -planeModel и flightTime
			planeModel = PM;
			flightTime = FT;	
		}

		//Setters & Getters
		void set_planeModel(string x){//Сетър за planeModel
			planeModel = x;
		}
		string get_planeModel() const {//Гетър за planeModel
			return planeModel;
		}
		void set_flightTime(int x) {//Сетър за flightTime
			flightTime = x;
		}
		int get_flightTime() const {//Гетър за flightTime
			return flightTime;
		}
		//Оperators
		bool operator<(const CPlane& obj) const { //Предефиниране на оператора за по-малко '<'
			return flightTime > obj.flightTime;
		}

		//Оstream
		friend ostream &operator <<(ostream& out, CPlane& obj);//Декларирам приятелска функция за потоков изход

};
	ostream &operator <<(ostream& out, CPlane& obj) {//тялото на приятелската функция за потоков изход
		return out <<endl<<"Plane model :"<< obj.planeModel <<"  /  Flight-time: "<< obj.flightTime;
	}

	class CAirtravel{//Създавам класът CAirtravel
	public:
		string compName;//име на компанията
		string nationality;//националност на компанията

		map<CPlane, unsigned int>cplane_map;//map държи CPlane обекти като 'Key' и unsigned int(брой дестинаций) като 'Value'
		map<CPlane, unsigned int>::iterator iter2;//Итератор ,който итерира cplane_map
		//За да получа достъп до данните от клас CPlane използвам 2 вектора - v1 и v2. 
		//Разделям 'Key' и 'Value' на map cplane_map и записвам разделените стойности във 2 вектора v1 и v2.
		vector<CPlane>v1;//Във вектор v1 записвам 'Key' от тип cplane_map (CPlane обекти)
		vector<unsigned int>v2;//Във вектор v2 записвам 'Value' от cplane_map (unsigned int - брой дестинаций)

		multimap<string, unsigned int>multiM_destination_container;//multimap държи string (дестинация) като 'Key' и unsigned int(брой полети към дестинацията) като 'Value'
		multimap<string, unsigned int>::iterator iter3;//Итератор ,който итерира multiM_destination_container
		//за по-лесен достъп. разделям 'Key' и 'Value' от multimap multiM_destination_container и записвам разделените стойности във 2 вектора, v3 и v4.
		vector<string>v3;//Във вектор v1 записвам 'Key' от тип string (дестинация)
		vector<unsigned int>v4;//Във вектор v2 записвам 'Value' от cplane_map (unsigned int - брой полети към дестинацията)

		static int French_count;//static int следи броя на френските компании
		static int Number_of_destinations;//броя на дестинациите на всички френски компании

		CAirtravel();//Дефалтен конструктор.

		//Експлицитен конструктор, приемащ аргументи за променливите -compName(име на компанията), nationality(националност на компанията),map - cplane_map съдържащ(CPlane обекти и брой дестинаций) и multimap - multiM_destination_container съдържащ(дестинация и брой полети към нея)
		CAirtravel(string compName_Arg, string nationality_Arg, map<CPlane, unsigned int>cplane_map_Arg,multimap<string, unsigned int> mp_Arg) {
			compName = compName_Arg;
			nationality = nationality_Arg;
			cplane_map = cplane_map_Arg;
			multiM_destination_container = mp_Arg;
			push_in_vector();//<- тази функция разделя 'Key' и 'Value' от map cplane_map и записва разделените стойности във вектор v1 и v2.
			push_in_vector2();//<- тази функция разделя 'Key' и 'Value' от multimap multiM_destination_container и записва разделените стойности във вектор v3 и v4.
			if (nationality == "French" || nationality == "french") {//проверявам дали новосъздадения обек ,притижава френска националност
				frenchFlights();//изпълнява функцията frenchflights() и по този начин инкрементира static променливата "French_count" и добавя броя на полетите от тази френска компания към static променливата "Number_of_destinations" ,която държи проя полети за всички френски компании
			}
			less_than_2k();
		}

		//тази функция се изъплнпва само когато обекта който създаваме е със френска националност
		void frenchFlights() {//тази функция следи колко обекта притежаващи френска националност са създадени
			map<CPlane, unsigned int>::iterator itr;
			French_count++;//увеличавам тоталния брой френски авиокомпланий със 1
			for (itr = cplane_map.begin(); itr != cplane_map.end(); itr++) {
				Number_of_destinations += itr->second;//добавям броя на дестинациите ,на новия обект към тоталния брой на всички дестинации от френски компаний
			}
		}

		void push_in_vector() {//записвам данните от cplane_map във двата вектора
			iter2 = cplane_map.begin();
			for (int i = 0; i < cplane_map.size(); i++) {//итерирам през cplane_map
				v1.push_back(iter2->first);//записвам всички 'kays'(CPlane обекти) на cplane_map във v1
				v2.push_back(iter2->second);//записвам всички 'values'(unsigned int - брой дестинации) на cplane_map във v2
				++iter2;//инкрементирам итератора ,и преминавам към следващата двойка от cplane_map
			}
		}

		void push_in_vector2() {//записвам данните от cplane_map във двата вектора
			iter3 = multiM_destination_container.begin();
			for (int i = 0; i < multiM_destination_container.size(); i++) {//итерирам през multiM_destination_container
				v3.push_back(iter3->first);//записвам всички 'kays'(дестинация) на multiM_destination_container във v3
				v4.push_back(iter3->second);//записвам всички 'values'(unsigned int - брой полети към дестинацията) на multiM_destination_container във v4
				++iter3;//инкрементирам итератора ,и пременавам към следващата двойка от multiM_destination_container
			}
		}

		void less_than_2k() {//функция която зивежда на екран лист със всички самолети със по-малко летателни часове от 2000 и повече дестинации от 10
			list<CPlane>P_list;//Във този лист вкарвам CPlane обекти които имат по-малко летателни часове от 2000 и повече полети от 10
			list<CPlane>::iterator p;//итератор за P_list
			
			vector<CPlane>::iterator Cplane_iter;//итератор за Cplane обектите в вектор v1
			vector<unsigned int>::iterator destination_iter;//итератор за int (дестинациите) в вектор v2

			destination_iter = v2.begin();
			for(Cplane_iter = v1.begin(); Cplane_iter != v1.end(); Cplane_iter++) {//този цикъл ще се повтори докато итератора на cplane_map не стигне края		
				if (Cplane_iter->get_flightTime() < 2000 && (*destination_iter)>10) {
					P_list.push_back((*Cplane_iter));//във P_list вкарвам Cplane обекти
				}
				destination_iter++;
			}
			for (p = P_list.begin(); p != P_list.end(); p++) {//цикъл за извеждане на листа ,на екран
				cout << (*p);
			}
		}

		bool operator<(const CAirtravel& obj) const {//Предефиниране на оператора за по-малко '<'
			return compName > obj.compName;
		}
		
};

	class CAirport {//Създавам класът CAirport
		//информация за летището
		string airportName;//име на летището
		unsigned int n_flights;//номер на полет
		multimap<CAirtravel, unsigned int>airtravel;//контейнер съдържащ данните за различните авиокомпании и брой полети
	public:
		CAirport();//Дефалтен конструктор.
		//Експлицитен конструктор
		CAirport(string airportName_arg, unsigned int n_flights_arg, multimap<CAirtravel, unsigned int>airtravel_arg) {//приема(име на летището, номер на полет ,контейнер съдържащ данните за различните авиокомпании и брой полети
			airportName = airportName_arg;
			n_flights = n_flights_arg;
			airtravel = airtravel_arg;
			show_french_flights();//изкарвам френските полети на екран
		}

		CAirport(string filename) {//Експлицитен конструктор за файл
			ifstream ObjFile(filename);//създавам файлов овект(ObjFile)
			string airportName_arg;// във airportName_arg записвам име на летището (от файл)
			unsigned int n_flights_arg;// във n_flights_arg записвам номер на полет на летището (от файл)

			//запълвам тези 2 контейнера със данни от файла ,и ги вкарвам във CAirtravel обект
			multimap<string, unsigned int>destinations_container1;
			map<CPlane, unsigned int>class1_container1;

			multimap<CAirtravel, unsigned int>Container_for_CAirport;//подавам Container_for_CAirport във конструктора на Airport
			
			int rollControl = 0;//използвам rollControl за да покажа на програмата кой ред от текстовия документ със какво е пълен
			//когато програмата прочете 1 ред от файла, rollControl се инкрементира
			//в зависимост от числото във rollControl, програмата ще изпълни различен if statement

			while (ObjFile >> airportName_arg >> n_flights_arg) {//записвам името на летището и номера му във airportName_arg и n_flights_arg
				if (ObjFile) {//условието във if statementa  ще се изпълнява докато има данни във файла
					string line;//във line се записват данните от файла, ред по ред
					while (getline(ObjFile, line)) {//този цикъл се повтаря докато показателя на файла не стигне края
						rollControl++;//rollcontrol се инкрементира
						istringstream iss(line);//създавам istringstream обект (iss) който копира данните от line(1 ред от файла)
							if (rollControl == 2) {//ако rollControl е 2 ,то filepointera е на ред който съдържа данните за - марка на самолета , литателни часове и брой дестинации на самолета
									while (iss) {//цикъла се повтаря докато показателя на iss не стигне края на реда
									string subs, dubs, mubs;//дъздавам 3 променливи които се подават като аргумент за създаване и съхраняване на обект от тип CPlane във class1_container1
									//вкарвам стринговете от iss във новосъздадените променливи
									iss >> subs;
									iss >> dubs;
									iss >> mubs;
									if (subs == "") {//ако има празни променливи, ще прискочим тази итерация в цикъла
										continue;
									}
									class1_container1.insert(pair<CPlane, unsigned int>(CPlane(subs, stoi(dubs)), stoi(mubs)));
								}
							}
							if (rollControl == 3) {//ако rollControl е 3 ,то filepointera е на ред който съдържа данните за - име на дестинацията и брой полети към нея
								while (iss) {//цъкъла се повтаря докато pointer на iss не стигне края си
									string subs, dubs; // дъздавам 2 променливи които се дъхраняват във map destinations_container1
									//вкарвам стринговете от iss във новосъздадените променливи
									iss >> subs;
									iss >> dubs;
									if (subs == "") {//ако има празни променливи, ще прискочим тази итерация в цикъла
										continue;
									}
									destinations_container1.insert(pair<string, unsigned int>(subs, stoi(dubs)));
								}
							}
							if (rollControl == 4) {//ако rollControl е 4 ,то показателя на файла е на ред който съдържа данните за -име, националност и брой дестинации на компанията
								while (iss) {//цъкъла се повтаря докато pointer на iss не стигне края си
									string subs, dubs, mubs;
									//вкарвам стринговете от iss във новосъздадените променливи
									iss >> subs;
									iss >> dubs;
									iss >> mubs;
									if(!(subs==""|| subs == ""|| mubs == ""))//ако има празни променливи, ще прискочим тази итерация в цикъла
									Container_for_CAirport.insert(pair<CAirtravel, unsigned int>(CAirtravel(subs, dubs, class1_container1, destinations_container1), stoi(mubs)));
								}
								
							}
							if (rollControl == 5) {// ако rollControl е 5, ще преминем към създаването на нов Airtravel обект
								//изтривам старите данни от контейнерите 
								destinations_container1.clear();
								class1_container1.clear();
								rollControl = 1;//rollControl става 1 и цикъла отново започва да взема от файла, докато не свършат
							}			
						}
					}
				}
				//присвояване на данни
				airportName = airportName_arg;
				n_flights = n_flights_arg;
				airtravel = Container_for_CAirport;
				show_french_flights();//изкарвам френските полети на екран
			}

		void Func1_get_flights_and_owner(string arg) {//при подаден аргумен ,марка самолет, веръща името на авиокомпанията собственик на самолета
			bool checkifmatch = true;//болеан променливата се използава за проверка, дали има самолет със същата марка като тази подадена като аргумент
			multimap<CAirtravel, unsigned int>::iterator iter;//създавам итератор за данните за различните авиокомпании и брой полети

			for (iter = airtravel.begin(); iter != airtravel.end(); iter++) {//итерирам през различните airtravel обекти
				for (int j = 0; j < iter->first.v1.size(); ++j) {//итерирам през различните CPlane обекти
					if (iter->first.v1[j].get_planeModel() == arg) {//ако модела на самолета съвпада със подадения аргумент, ще го извадя на екран
						cout<<endl<< arg<<" - belongs to " << iter->first.compName <<" and has " << iter->first.v2[j] <<" flights";
						checkifmatch = false;//checkifmatch става false ,което значи че има поне 1 самолет със подадения модел
					}
				}
			}
			if (checkifmatch)// ако не няма нито 1 самолет със подадения модел ще се изведе на екран съобщение че няма съвпадения
				cout<< endl << "no panes with this model were found";
		}

		void Func2_get_max_of_destination(string arg) {//при подаден аргумен име на дестинация, връща имато на компанията със най-много полети към нея
			bool checkifmatch = true;//болеан променливата се използава за проверка, дали има самолет със същата марка като тази подадена като аргумент
			int savemax = 0;//запазва най-многото полети ,по който се прави проверката
			string savename = "no complany with flights to destination";//запазва имато на компанията със най-много полети
			multimap<CAirtravel, unsigned int>::iterator iter;//създавам итератор за данните за различните авиокомпании и брой полети

			for (iter = airtravel.begin(); iter != airtravel.end(); iter++) {//итерирам през различните airtravel обекти
				for (int j = 0; j < iter->first.v3.size(); ++j) {//итерирам през всички дестинации
					if (arg == iter->first.v3[j]) {//когато дестинацията съвпадне със аргумента ще започне нова проверка 
							if (iter->first.v4[j] > savemax) {//тази нова преверка ще провери дали новата компания има повече извършени полети
								savemax = iter->first.v4[j];//новата компания става 'компанията със най-много полети'
								savename = iter->first.compName;
								checkifmatch = false;//checkifmatch става false ,което значи че има поне една компанията със подадената дестинация
							}
					}
				}
			}
			if (checkifmatch)// ако не няма нито 1 самолет със подадения модел ще изведем на екран съобщение че няма съвпадения
				cout << endl << "no planes with this model were found";
			else cout << savemax << " flights from " << savename;// изкарвам компанията със най-много полити
		}

		void Func3_getPlane_with_max_destinations() {//връща марка самолет със най-много дестинаций
			multimap<CAirtravel, unsigned int>::iterator iter;//създавам итератор за данните за различните авиокомпании и брой полети
			int savemax = 0;//запазва броя полети ,по който се прави проверката
			string savename = "no plane";//запазва марката на самолета
			for (iter = airtravel.begin(); iter != airtravel.end(); iter++) {//итерирам през различните airtravel обекти
				for (int j = 0; j < iter->first.v1.size(); ++j) {//итерирам през различните CPlane обекти
					if (iter->first.v2[j] > savemax) {//тази преверка ще провери дали новия CPlane обект има повече дестинации
						savemax = iter->first.v2[j];//новата компания става 'самолет със най-много дестинаций'
						savename = iter->first.v1[j].get_planeModel();
					}
				}
			}
			cout <<endl << savename<<" with "<< savemax << " destinations ";// изкарвам самолета със най-много дестинации
		}

		void Func4_get_max_flights_destination_by_company(string arg) {//при подаден аргумент авиокомпания, връща дестинацията със най-много полети
			multimap<CAirtravel, unsigned int>::iterator iter;//създавам итератор за данните за различните авиокомпании и брой полети
			int savemax = 0;//запазва броя полети към дестинация,по което се прави проверката
			string savename = "no company";;//запазва името на дестинацията
			for (iter = airtravel.begin(); iter != airtravel.end(); iter++) {//итерирам през различните airtravel обекти
				if(iter->first.compName == arg){//проверка дали сегашната компания(в итератора) ствпада със подадения аргумант
					for (int j = 0; j < iter->first.v1.size(); ++j) {//итерирам през различните CPlane обекти
						if (iter->first.v4[j] > savemax) {//тази проверка ще провери дали броя дестинации е по-голям от предишния макс
							savemax = iter->first.v4[j];
							savename = iter->first.v3[j];
						}
					}
				}
			}
			cout << endl << savemax << " " << savename;//извеждане на екран
		}

		vector<CPlane> Func5_return_vector_of_Cplanes() {//връща векрор от самолетите със над 10000 литатени часове които ползват летище София
			vector<CPlane>localV1;//във този вектор вкарвам обекти от тип CPlane ,които имат повече от 10000 летатилни часове
			if (airportName == "sofia"|| airportName == "Sofia") {//проверка дъли самолетите ползавт летище София
				multimap<CAirtravel, unsigned int>::iterator iter;//създавам итератор за данните за различните авиокомпании и брой полети
				for (iter = airtravel.begin(); iter != airtravel.end(); iter++) {//итерирам през различните airtravel обекти
					for (int j = 0; j < iter->first.v1.size(); ++j) {//итерирам през различните CPlane обекти
						if (iter->first.v1[j].get_flightTime() > 10000) {//проверка дъли самолета има 10000 или повече летателни часове
							localV1.push_back(iter->first.v1[j]);//вкарвам CPlane обекта във вектор localV1
						}
					}
				}
			}
			return localV1;//връща вектор от CPlane обекти
		}

		void show_french_flights() {//тази функция извежда броя на френските авиокомпании и техните полити
			multimap<CAirtravel, unsigned int>::iterator iter;
			iter = airtravel.begin();
			cout << "\n\nNumber of French flights: " << iter->first.French_count << "\nNumber of destinations by French companies: " << iter->first.Number_of_destinations;//изкарвам броя на всички френски компаний и броя на техните дестинации
		}
	
	};

		//част от декларацията на static променливите отговорни за тоталния брой на френските авиокомпании
		int CAirtravel::French_count = 0;
		int CAirtravel::Number_of_destinations = 0;

		int main() {
			int izbor=0;//променливата izbor позволява на потребителя да избира различни оцпий
			do {//докато потребителя не избере нещо различно от 0 ,този цикъл ще се повтаря
				cout << "Please enter the corresponding number\n1. Use hardcoded data\n2. Use file data\nInput any other number to exit program\n";
				cin >> izbor;
			} while (izbor == 0);

			if (izbor == 1) {
				//създавам контейнери за hardcoded данни
				map<CPlane, unsigned int>class1_container1;//конейнер за Atravelobj1
				map<CPlane, unsigned int>class1_container2;//конейнер за Atravelobj2
				map<CPlane, unsigned int>class1_container3;//конейнер за Atravelobj3

				multimap<string, unsigned int>destinations_container1;//конейнер за Atravelobj3
				multimap<string, unsigned int>destinations_container2;//конейнер за Atravelobj3
				multimap<string, unsigned int>destinations_container3;//конейнер за Atravelobj3

				multimap<CAirtravel, unsigned int>Container_for_CAirport;
			
				//				МАРКА | ЛИТАТЕЛНИ ЧАСОВЕ
				//данни за Atravelobj1
				CPlane Cobj1("Boeing 777", 500);
				CPlane Cobj2("Airbus a380", 1000);
				CPlane Cobj3("Boeing 737", 15000);
				CPlane Cobj4("Concorde", 2500);
				//данни за Atravelobй2
				CPlane Cobj5("falcon 7x", 11000);
				CPlane Cobj6("Beriev Be30", 2500);
				CPlane Cobj7("Pilatus porter", 21000);
				CPlane Cobj8("Ilyushin il96", 800);
				//данни за Atravelobj3
				CPlane Cobj9("Sukhoi KR860", 7900);
				CPlane Cobj10("Comac C939", 4500);

				//данни за Atravelobj1
				class1_container1.insert(pair<CPlane, unsigned int>(Cobj1, 9));
				class1_container1.insert(pair<CPlane, unsigned int>(Cobj2, 36));
				class1_container1.insert(pair<CPlane, unsigned int>(Cobj3, 76));
				class1_container1.insert(pair<CPlane, unsigned int>(Cobj4, 31));
				//данни за Atravelobj2
				class1_container2.insert(pair<CPlane, unsigned int>(Cobj5, 19));
				class1_container2.insert(pair<CPlane, unsigned int>(Cobj6, 45));
				class1_container2.insert(pair<CPlane, unsigned int>(Cobj7, 89));
				class1_container2.insert(pair<CPlane, unsigned int>(Cobj8, 47));
				//данни за Atravelobj3
				class1_container3.insert(pair<CPlane, unsigned int>(Cobj9, 7));
				class1_container3.insert(pair<CPlane, unsigned int>(Cobj10, 12));


				//									ДЕСТИНАЦИЯ | БРОЙ ПОЛЕТИ
				//данни за Atravelobj1
				destinations_container1.insert(pair<string, unsigned int>("Tokyo", 47));
				destinations_container1.insert(pair<string, unsigned int>("Varna", 51));
				destinations_container1.insert(pair<string, unsigned int>("London", 121));
				destinations_container1.insert(pair<string, unsigned int>("New York", 64));
				//данни за Atravelobj2
				destinations_container2.insert(pair<string, unsigned int>("Tokyo", 19));
				destinations_container2.insert(pair<string, unsigned int>("London", 7));
				destinations_container2.insert(pair<string, unsigned int>("Mexico city", 2));
				destinations_container2.insert(pair<string, unsigned int>("Shenzhen", 22));
				//данни за Atravelobj3
				destinations_container3.insert(pair<string, unsigned int>("Rome", 32));
				destinations_container3.insert(pair<string, unsigned int>("Shenzhen", 90));

				cout << "\nlist of palnes with less than 2000 flight hours and more than 10 destinations:";

				//създавам 3 CAirtravel обекта, които послсе вакарвам във контейнер Container_for_CAirport
				CAirtravel Atravelobj1("French Bee", "French", class1_container1, destinations_container1);
				CAirtravel Atravelobj2("Lufthansa", "German", class1_container2, destinations_container2);
				CAirtravel Atravelobj3("Air France", "French", class1_container3, destinations_container3);
				//PLANE ОБЕКТ | БРОЙ ПОЛЕТИ
				Container_for_CAirport.insert(pair<CAirtravel, unsigned int>(Atravelobj1, 338));
				Container_for_CAirport.insert(pair<CAirtravel, unsigned int>(Atravelobj2, 76));
				Container_for_CAirport.insert(pair<CAirtravel, unsigned int>(Atravelobj3, 122));

				CAirport AirportObj("Sofia", 467, Container_for_CAirport);

				string StringArg;//StringArg се използва за подаване на аргументи от тип String към член функциите на клас CAirport
				vector<CPlane>vectorF5;//съзадвам вектор и итератор, за работа със член функция Func5_return_vector_of_Cplanes()
				vector<CPlane>::iterator VF5iter;

				while (true){//докато потребителя не въведе 6 прогармата ще продължи
					cout << "\n\nPlease enter the coresponding number:\n1. return owner and number of flights of a plane\n2. return the company with the most flights to a destination\n3. return the plane with the most destinations\n4. return the destination with the most flights by a given company\n5. return list of planes that have more than 10000 in airport Sofia\n6. exit program\n";
					cin >> izbor;
					switch (izbor)//този switch позвулява на потребителя да избира член-функция 
					{
					case 1://при подаден аргумен марка самолет веръща имато на авиокомпанията собственик на самолета
						cout << "Enter a plane model: ";
						cin.ignore(256, '\n');
						getline(cin, StringArg);//взимам текаста от целия ред
						AirportObj.Func1_get_flights_and_owner(StringArg);
						break;
					case 2://при подаден аргумен име на дестинация, връща името на компанията със най-много полети до нея
						cout << "Enter a destination: ";
						cin.ignore(256, '\n');
						getline(cin, StringArg);//взимам текста от целия ред
						AirportObj.Func2_get_max_of_destination(StringArg);
						break;
					case 3://връща марка самолет със най-много дестинации
						AirportObj.Func3_getPlane_with_max_destinations();
						break;
					case 4://при подаден аргумент виокомпания, връща дестинацията със най-много полети
						cout << "Enter a company: ";
						cin.ignore(256, '\n');
						getline(cin, StringArg);//взимам текста от целия ред
						AirportObj.Func4_get_max_flights_destination_by_company(StringArg);
						break;
					case 5://връща векрор от самолетите със над 10000 литатени часове които ползват летище София
						vectorF5 = AirportObj.Func5_return_vector_of_Cplanes();
						for (VF5iter = vectorF5.begin(); VF5iter != vectorF5.end(); VF5iter++) {//изкарвам на екран всички самолети със повече от 10000 литатени часове които ползват летище София
							cout << (*VF5iter);
						}
						break;
					case 6://спира програмата
						exit(1);
						break;
					default:
						cout << "\nInvalid input";
						break;
					}
				}
				
			}
			else if (izbor == 2) {
			string StringArg;//StringArg се използва за подаване на аргументи от тип String към член функциите на клас Cairport и за избиране на файл при работа с файл
			vector<CPlane>vectorF5;//съзадвам вектор и итератор, за работа със член-функция Func5_return_vector_of_Cplanes()
			vector<CPlane>::iterator VF5iter;

			cout << "please enter the name of the file, you wish to use:\n";
			cin >> StringArg;
			CAirport AirportObj(StringArg);//продавам стринг със имато на кайла към конструктора на AirportObj
		
			while (true) {//докато потребителя не въведе 6 прогармата ще продължи
				cout << "\n\nPlease enter the coresponding number:\n1. return owner and number of flights of a plane\n2. return the company with the most flights to a destination\n3. return the plane with the most destinations\n4. return the destination with the most flights by a given company\n5. return list of planes that have more than 10000 in airport Sofia\n6. exit program\n";
				cin >> izbor;
				switch (izbor)//този switch позвулява на потребителя да избира член-функция 
				{
				case 1://при подаден аргумен марка самолет веръща имато на авиокомпанията собственик на самолета
					cout << "Enter a plane model: ";
					cin.ignore(256, '\n');
					getline(cin, StringArg);//взимам текаста от целия ред
					AirportObj.Func1_get_flights_and_owner(StringArg);
					break;
				case 2://при подаден аргумен име на дестинация, връща името на компанията със най-много полети до нея
					cout << "Enter a destination: ";
					cin.ignore(256, '\n');
					getline(cin, StringArg);//взимам текста от целия ред
					AirportObj.Func2_get_max_of_destination(StringArg);
					break;
				case 3://връща марка самолет със най-много дестинации
					AirportObj.Func3_getPlane_with_max_destinations();
					break;
				case 4://при подаден аргумент виокомпания, връща дестинацията със най-много полети
					cout << "Enter a company: ";
					cin.ignore(256, '\n');
					getline(cin, StringArg);//взимам текста от целия ред
					AirportObj.Func4_get_max_flights_destination_by_company(StringArg);
					break;
				case 5://връща векрор от самолетите със над 10000 литатени часове които ползват летище София
					vectorF5 = AirportObj.Func5_return_vector_of_Cplanes();
					for (VF5iter = vectorF5.begin(); VF5iter != vectorF5.end(); VF5iter++) {//изкарвам на екран всички самолети със повече от 10000 литатени часове които ползват летище София
						cout << (*VF5iter);
					}
					break;
				case 6://спира програмата
					exit(1);
					break;
				default:
					cout << "\nInvalid input";
					break;
				}
			}
			}
			system("pause");
			return 0;
		}