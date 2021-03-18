#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
class Normal_Vehicle
{

public:
    string engine_type;
    string model_number;

    double engine_power;
    string tiresize;
    Normal_Vehicle();
    Normal_Vehicle(string mo_n,double power, string tire,string typ);

};
Normal_Vehicle::Normal_Vehicle(){
}
Normal_Vehicle::Normal_Vehicle(string mo_n,double power, string tire, string typ)
{
    cout<<"Normal Vehicle is adding"<<endl;
    model_number=mo_n;
    engine_power=power;
    tiresize=tire;
    engine_type=typ;
}
class Sports_Vehicle: public Normal_Vehicle
{
public:

    Sports_Vehicle(string mo_n,double power, string tire);
};

Sports_Vehicle::Sports_Vehicle(string mo_n,double power, string tire)
{
    bool turbo= true;
    model_number=mo_n;
    engine_power=power;
    tiresize=tire;
    engine_type="oil";

}


class Heavy_Vehicle: public Normal_Vehicle
{
    double weight;
public:

    Heavy_Vehicle(string mo_n,double power, string tire,double w);

};

Heavy_Vehicle::Heavy_Vehicle(string mo_n,double power, string tire,double w)
{
    weight=w;
    model_number=mo_n;
    engine_power=power;
    tiresize=tire;
    engine_type="diesel";
}
int main()
{
    vector<Normal_Vehicle>norm_vector;
    vector<Sports_Vehicle>sport_vector;
    vector<Heavy_Vehicle>heav_vector;
    cout<<"                               Vehicle Showroom                         "<<endl;
    int option;
    string v_type;
    string m;
    double p;
    string eng;
    string t;
    int visitor=30;

    double w;
    cout<<"Press 1 for Add,2 for Remove and 3 for getting list and 4 for getting list of vehicles with expected visitor count"<<endl;
    cout<<"Enter option:";
    while(scanf("%d",&option)!=EOF)
    {
        if(option==1)
        {
            cout<<"Enter the type of vehicle :";
            cin>>v_type;

            label1: if(v_type=="normal"||v_type=="NORMAL"||v_type=="Normal")
            {

                cout<<"Enter model:";
                cin>>m;

                cout<<endl<<"Enter Engine Power:";
                cin>>p;

                cout<<"Enter Tire size:";

                cin>>t;

                cout<<endl<<"Enter engine type:";
                cin>>eng;

                norm_vector.push_back(Normal_Vehicle(m,p,t,eng));

            }
            else if(v_type=="sports"||v_type=="SPORTS"||v_type=="Sports")
            {

                cout<<"Enter model:";
                cin>>m;

                cout<<endl<<"Enter Engine Power:";
                cin>>p;

                cout<<"Enter Tire size:";

                cin>>t;
                sport_vector.push_back(Sports_Vehicle(m,p,t));
                visitor+=20;

            }
            else if(v_type=="Heavy"||v_type=="heavy"||v_type=="HEAVY")
            {
                cout<<"Enter model:";
                cin>>m;

                cout<<endl<<"Enter Engine Power:";
                cin>>p;

                cout<<"Enter Tire size:";

                cin>>t;
                cout<<"Enter weight of the vehicle:";
                cin>>w;
                heav_vector.push_back(Heavy_Vehicle(m,p,t,w));
            }
            else
            {
                cout<<"Type valid vehicle type: Normal / Sports / Heavy"<<endl;
                cin>>v_type;
                goto label1;
            }

        }
        if(option==2)
        {
            cout<<"Enter vehicle type of the vehicle you want to remove:";
            cin>>v_type;

            label2:if(v_type=="normal"||v_type=="NORMAL"||v_type=="Normal")
            {
                cout<<"Enter the model number :";
                cin>>m;
                if(norm_vector.size()==0)
                {
                    cout<<"Sorry!No normal vehicle left."<<endl;
                }
                else
                {
                    for(vector<Normal_Vehicle>::iterator i=norm_vector.begin(); i!=norm_vector.end(); ++i)
                    {
                        if(i->model_number==m)
                        {
                            norm_vector.erase(i);
                            break;
                        }
                    }
                }
            }
            else if(v_type=="Sports"||v_type=="SPORTS"||v_type=="sports")
            {
                  cout<<"Enter the model number :";
                cin>>m;
                if(sport_vector.size()==0)
                {
                    cout<<"Sorry!No Sports Vehicle Left."<<endl;
                }
                else
                {
                    for(vector<Sports_Vehicle>::iterator i=sport_vector.begin(); i!=sport_vector.end(); ++i)
                    {
                        if(i->model_number==m)
                        {
                            sport_vector.erase(i);
                            break;
                        }
                    }
                }
            }
             else if(v_type=="Heavy"||v_type=="HEAVY"||v_type=="heavy")
            {
                  cout<<"Enter the model number :";
                cin>>m;
                if(heav_vector.size()==0)
                {
                    cout<<"Sorry!No Heavy vehicle left"<<endl;
                }
                else
                {
                    for(vector<Heavy_Vehicle>::iterator i=heav_vector.begin(); i!=heav_vector.end(); ++i)
                    {
                        if(i->model_number==m)
                        {
                            heav_vector.erase(i);
                            break;
                        }
                    }
                }
            }
            else
            {
                cout<<"Type valid vehicle type: Normal / Sports / Heavy"<<endl;
                cin>>v_type;
                goto label2;
            }

        }
        if(option==3)
        {

            cout<<"The list of all vehicles are given below:"<<endl;
            if(norm_vector.size()==0)
                cout<<"No normal vehicle in this showroom"<<endl;

        else
        {
            cout<<endl<<"List of Normal Vehicles in the showroom"<<endl;
            cout<<endl<<"Model"<<"  "<<"Engine Type"<<" "<<"Tire Size"<<" "<<"Engine Power(HP)"<<endl;
            for(vector<Normal_Vehicle>::iterator i=norm_vector.begin(); i!=norm_vector.end(); ++i)
            {
                cout<<i->model_number<<"   "<<i->engine_type<<"  "<<i->tiresize<<" "<<i->engine_power<<endl;
            }
        }
        if(sport_vector.size()==0)
                cout<<"No Sports vehicle in this showroom"<<endl;

        else
        {
            cout<<endl<<"List of Sports Vehicles in the showroom"<<endl;
            cout<<endl<<"Model"<<"  "<<"Engine Type"<<" "<<"Tire Size"<<" "<<"Engine Power(HP)"<<endl;
            for(vector<Sports_Vehicle>::iterator i=sport_vector.begin(); i!=sport_vector.end(); ++i)
            {
                cout<<i->model_number<<"       "<<i->engine_type<<"      "<<i->tiresize<<"     "<<i->engine_power<<endl;
            }
        }
        if(heav_vector.size()==0)
                cout<<"No Heavy vehicle in this showroom"<<endl;

        else
        {
            cout<<endl<<"List of Heavy Vehicles in the showroom"<<endl;
            cout<<endl<<"Model"<<"  "<<"Engine Type"<<" "<<"Tire Size"<<" "<<"Engine Power(HP)"<<endl;
            for(vector<Heavy_Vehicle>::iterator i=heav_vector.begin(); i!=heav_vector.end(); ++i)
            {
                cout<<i->model_number<<"       "<<i->engine_type<<"      "<<i->tiresize<<"     "<<i->engine_power<<endl;
            }
        }
        }
        if(option==4){
            cout<<"The regular expected visitor count of the vehicle showroom is"<<visitor<<endl;
        }
        cout<<"Enter option:";
    }




    return 0;
}
