#include <iostream>
#include <unistd.h>

using namespace std;

double pop;
double r;
int generation = 0;
double positiveCases;
int percentPositive;

void graphicsStable(int percentPositive_stable){ /// BUG : this function has some bugs with simfrom
    /* Make sure the graphics start from the same column */
    if(generation < 10.0 && percentPositive_stable < 10.0){
        cout << "  ";
    }
    if(generation >= 10.0 && percentPositive_stable < 10.0){
        cout << " ";
    }
    if(generation < 10.0 && percentPositive_stable >= 10.0){
        cout << " ";
    }
    if(generation >= 10.0 && percentPositive_stable >= 10.0){
        cout << "";
    }
}

void Graphics(int percentPositive_drawing, string graph_char){
    for(int o = 0; o < percentPositive_drawing; o++){
        cout << graph_char;
    }
    cout << "" << endl;
}

int main()
{
    cout << "" << endl;
    cout << "spreadOut" << endl;
    cout << "the tool for simulating medical or social disease spreading." << endl;
    cout << "Type 'help' for printing help message." << endl;
    cout << "" << endl;
    string mode;


    while(true){
        cout << " >> ";
        cin >> mode;

        if(mode == "help"){
            cout << "" << endl;
            cout << "sim            start a simulation from 1 positive case" << endl;
            cout << "simfrom        start a simulation from a chosen number of positive cases" << endl;
            cout << "simfrom-p      start a simulation with a progressing R number" << endl;
            cout << "simfrom-p-v    start a simulation with a vaccine" << endl;
            cout << "quit           quit spreadOut" << endl;
            cout << "" << endl;
        }

        if(mode == "quit"){
            break;
        }

        if(mode == "sim"){
            generation = 0;
            cout << "" << endl;
            cout << "R = " ;
            cin >> r;
            cout << "Population : " ;
            cin >> pop;
            positiveCases = 1;

            cout << "" << endl;

            while(positiveCases < pop){
                generation += 1;
                percentPositive = positiveCases/(pop/100);
                positiveCases *= r;

                cout << "Generation " << generation << " : " << percentPositive << "%   ";

                graphicsStable(percentPositive);
                Graphics(percentPositive, "|");

            }
        }

        if(mode == "simfrom"){
            generation = 0;
            cout << "" << endl;
            cout << "Confirmed positive cases : ";
            cin >> positiveCases;
            cout << "Population : ";
            cin >> pop;
            percentPositive = (100/pop)*positiveCases; // percent of positive
            cout << "R = ";
            cin >> r;

            cout << "" << endl;

            while(positiveCases < pop && positiveCases >= 1){
                generation += 1;
                percentPositive = positiveCases/(pop/100);
                positiveCases *= r;

                cout << "Generation " << generation << " : " << percentPositive << "% ";

                graphicsStable(percentPositive);
                Graphics(percentPositive, "|");
            }
        }

        if(mode == "simfrom-p"){
            generation = 0;
            cout << "" << endl;
            cout << "Confirmed positive cases : ";
            cin >> positiveCases;
            cout << "Population : ";
            cin >> pop;
            percentPositive = (100/pop)*positiveCases; // percent of positive
            cout << "R (at the first generation) = ";
            cin >> r;
            cout << "R progressing rate = ";
            double rprog;
            cin >> rprog;

            cout << "" << endl;

            while(positiveCases < pop && positiveCases >= 1){
                generation += 1;
                percentPositive = positiveCases/(pop/100);
                positiveCases *= r;
                r += rprog;

                cout << "Generation " << generation << " : " << percentPositive << "% ";

                graphicsStable(percentPositive);
                Graphics(percentPositive, "|");
            }
        }

        if(mode == "simfrom-p-v"){
            generation = 0;
            cout << "" << endl;
            cout << "Confirmed positive cases : ";
            cin >> positiveCases;
            cout << "Population : ";
            cin >> pop;
            percentPositive = (100/pop)*positiveCases; // percent of positive
            cout << "R (at the first generation) = ";
            cin >> r;
            cout << "R progressing rate = ";
            double rprog;
            cin >> rprog;
            cout << "Vaccinated population (in %) : ";
            double vax;
            cin >> vax;

            cout << "" << endl;

            while(positiveCases < pop && positiveCases >= 1){
                generation += 1;
                percentPositive = positiveCases/(pop/100);
                positiveCases *= r;
                if(positiveCases > (100-vax)) positiveCases /= r;
                r += rprog;

                cout << "Generation " << generation << " : " << percentPositive << "% ";

                graphicsStable(percentPositive);
                Graphics(percentPositive, "|");
                usleep(1000000);
            }
        }

    }
    return 0;
}
