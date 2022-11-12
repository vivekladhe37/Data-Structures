#include<iostream> //use objects and functions of iostream class for eg cout, cin etc
#include<fstream> //use objects and functions of fstream class for eg ifstream
#include<vector> //stl array of undefined size
#include<string> //use objects and functions of string class for eg getline
#include<sstream> // use objects and function of string stream class to extract integers from a line in the input files
#include<map> //use objects and functions of map class to maintian key value like structure
#include<unistd.h> //used to implement sleep method 
#include<math.h>

using namespace std;

int check_gain;
int gain_previous;

int max_g_value = -100;
string max_g_value_pair;

float initial_cut_size = 0.0;
float initial_cut_size_partition_two = 0.0;

float final_cut_size = 0.0;

vector<int> gains; //stores max gains

vector<string> partition_one;
vector<string> partition_one_iterator;

vector<string> partition_two;
vector<string> partition_two_iterator;

vector<string> locked_nodes_partition_one;
vector<string> locked_nodes_partition_two;

vector<string> final_partition_one;
vector<string> final_partition_two;

map<string, int> connected_pairs;
map<string, int> ::iterator connected_pairs_iterator;

map<string, float> D_VALUE_partition_one;
map<string, float> ::iterator D_VALUE_partition_one_iterator;

map<string, float> D_VALUE_partition_two;
map<string, float> ::iterator D_VALUE_partition_two_iterator;

class Connection {
     int degree;
     string nodes;

public:
    int getDegree() {
        return degree;
    }

    string getNodes(){
        return nodes;
    }

    void setDegree(int d){
        degree = d;
    }

    void setNodes(string n){
        nodes = n;
    }
};

bool match_pattern(string mystring, string current_node){
    int len_mystring = mystring.length();
    int len_current_node = current_node.length();
    int result = mystring.find(current_node);
    if(result == -1){
        return false;
    }
    
    //cout<<result<<endl;
    char extra = mystring[len_current_node + result];
    //cout<<extra<<endl;
    if (isalpha(extra)){
        return true;
    }
    else if(isdigit(extra))
    {
        return false;
    }
    else{
        return true;
    }
}

int fetch_integer(string req_info)
{
    
    string str;
    str = req_info;
    string temp_str;
    int temp_int;
    int req_num;
    stringstream ss(str); //converting string into string stream

    while(!ss.eof()) // checking till we get an integer in the string line
    {
        ss >> temp_str; //extraction operator takes words in ss one by one 
        if(stringstream(temp_str) >> temp_int) //extracts any integer in and store it in temp_int if available
        {
            req_num = temp_int;
        }
        temp_str = ""; //flushing the temp_str
    }

    return req_num;
}

string fetch_nodes(string req_info)
{
    string temp_str;
    string req_str;
    temp_str = req_info; 
    stringstream ss(temp_str); //converting required string in string stream
    ss >> req_str; //extracting required terminal name from the string stream and storing in a string
    return req_str;
}


int main()
{
    map<string,int> G_VALUES;
    map<string,int>::iterator it;

    
    
    //cout<<"inside main function";
    vector<string> nodes; //array to store nodes
    
    string str; // for reading of file
    int numNodes; //stores the total number of nodes
    int numTerminals; //stores the total number of terminals
    int numPins; //stores the total number of pins in the complete circuit
    int netDegree; //stores the net degrees
    string node_abbreviation;
    int numObjects = 0;

    string node_filename;
    string net_filename;
    cout<<endl<<"Provide input nodes filename"<<endl;
    cin>>node_filename;
    cout<<endl<<"Provide input netts filename"<<endl;
    cin>>net_filename;

    ifstream fin_nodes (node_filename); //opens the nodes files and reads nodes hence not req to use open function
    {
        //cout<<"inside nodes.txt"<<endl;
        if(!fin_nodes)
        {
            cout<<"\n unable to open the file"<<endl;

        }
            
        while(!fin_nodes.eof())
        {
            //cout<<"inside while loop";
            getline(fin_nodes,str);
            {
                if (str.rfind("a") == 0 || str.rfind("p") == 0)
                {
                    node_abbreviation = fetch_nodes(str);
                    nodes.push_back(node_abbreviation); //entering nodes one by one in a vector array
                }

                else if (str.rfind("NumNodes") == 0) //condition to check number of nodes
                {
                    numNodes = fetch_integer(str);

                }

                else if (str.rfind("NumTerminals") == 0) //condition to check number of terminals
                {
                    numTerminals = fetch_integer(str);
                }
            }     
        }
        //cout<<"while loop ended"<<endl;
        
        fin_nodes.close();
    }

    Connection c[5000];
    
    //cout<<"Reading of nodes.txt is completed"<<endl;
    //cout<<"total nodes are "<<endl;
    /*
    for (int i = 0; i< nodes.size(); i++){
        cout<<nodes[i]<<endl;

    }
    */
    
    int len_partition_one = numNodes/2;

    for (int i=0; i<len_partition_one; i++){
        partition_one.push_back(nodes[i]);
    }

    for (int i = len_partition_one; i<numNodes; i++){
        partition_two.push_back(nodes[i]);
    }

    int len_partition_two = partition_two.size();
    
    /*
    cout<<endl<<"Partion one is "<<endl;
    for(int i = 0; i < partition_one.size(); i++)
    {
        cout<<partition_one[i]<<endl;
    }
    
    cout<<endl<<"Partion two is "<<endl;
    for(int i = 0; i < partition_two.size(); i++)
    {
        cout<<partition_two[i]<<endl;
    }
    */
    
    final_partition_one = partition_one;
    final_partition_two = partition_two;


    ifstream fin_nets (net_filename); //reads nets file
    {
        //cout<<"inside nets.txt"<<endl;
        if(!fin_nets)
        {
            cout<<"\n unable to open the file"<<endl;
        }
            
        while(!fin_nets.eof())
        {            
            getline(fin_nets,str); //to fetch the data line by line
            if (str.rfind("NumPins") == 0)
            {
                numPins = fetch_integer(str);
                
            }
            else if(str.rfind("NetDegree") == 0)
            {
                netDegree = fetch_integer(str);
                node_abbreviation = "";
                vector<string> temp_nodes;
                for (int i = 0; i< netDegree; i++)
                {
                    getline(fin_nets,str);
                    node_abbreviation += fetch_nodes(str);
                    temp_nodes.push_back(fetch_nodes(str));
                }
                for (int i = 0; i< temp_nodes.size(); i++){
                        for(int j = i+1; j < temp_nodes.size(); j++){
                            connected_pairs.insert(make_pair(temp_nodes[i]+temp_nodes[j],1));
                        }
                }

                c[numObjects].setDegree(netDegree); 
                c[numObjects].setNodes(node_abbreviation);
                numObjects = numObjects + 1; 
            }                   
        }
        fin_nets.close();
    }

    /*
    //Printing the total connections in nets file which is stored in form of map
    cout<<endl<<"Connections and it's respective value used for computing gain is as follows"<<endl;

    for(connected_pairs_iterator = connected_pairs.begin(); connected_pairs_iterator != connected_pairs.end(); connected_pairs_iterator++){
        cout<<"Conneciton between "<<connected_pairs_iterator->first<<" is having a value is "<<connected_pairs_iterator->second<<endl;
    }
    */
    /*
    cout<<endl<<"The total number of connections string in nets file is "<<numObjects<<endl;
    cout<<endl<<"The following is the connection and netdegree (fannout handling) for a each connection"<<endl;
    for(int i = 0; i< numObjects; i++){
        cout<<c[i].getDegree()<<" "<<c[i].getNodes()<<endl;
    }
    */

    //Start of Computation of D values of all the nodes in the first iteration
    float e_value_partition_one[len_partition_one];
    float i_value_partition_one[len_partition_one];
    float d_value_partition_one[len_partition_one];

    //Computing e values of partition 1 in fist iteration
    for(int x=0; x<len_partition_one; x++)
    {
        float current_external_node_degree = 0.0;
        string current_node = partition_one[x];
        for(int y=0; y<numObjects; y++){
            int fanout_counter = 1; 
            string current_object_string = c[y].getNodes();
            bool match_pattern_result = match_pattern(current_object_string , current_node);
            if(match_pattern_result == 1){
                for(int z = 0; z<len_partition_one; z++){
                    if(partition_one[z] == current_node){
                        continue;
                    }
                    else{
                        bool match_pattern_fanout = match_pattern(current_object_string,partition_one[z]);
                        if(match_pattern_fanout == 1){
                            fanout_counter += 1;
                        }
                        else{
                            continue;
                        }
                    }
                }
            }
            else{
                continue;
            }
            if(fanout_counter == c[y].getDegree()){
                continue;
            }
            else{
                current_external_node_degree += (float)(1/((float)fanout_counter));
            }            
        }
        e_value_partition_one[x] = current_external_node_degree;
        
    }

    
    //printing e values of partition 1
    //cout<<endl<<"Displaying e values of nodes in partition 1 iteration 1"<<endl;
    for(int i = 0; i < len_partition_one; i++){
        //cout<<partition_one[i]<<" has evalue of "<<e_value_partition_one[i]<<endl;
        initial_cut_size += e_value_partition_one[i]; 
    }
    
    cout<<endl<<"Initial Cut-Size"<<initial_cut_size<<endl;

    
    for(int x=0; x<len_partition_one; x++)
    {
        float current_internal_node_degree = 0.0;
        string current_node = partition_one[x];
        for(int y=0; y<numObjects; y++){
            int fanout_counter = 0; 
            string current_object_string = c[y].getNodes();
            bool match_pattern_result = match_pattern(current_object_string , current_node);
            if(match_pattern_result == 1){
                for(int z = 0; z<len_partition_one; z++){
                    if(partition_one[z] == current_node){
                        continue;
                    }
                    else{
                        bool match_pattern_fanout = match_pattern(current_object_string,partition_one[z]);
                        if(match_pattern_fanout == 1){
                            fanout_counter += 1;
                        }
                        else{
                            continue;
                        }
                    }
                }
            }
            else{
                continue;
            }
            if(fanout_counter == 0){
                current_internal_node_degree += 0;
            }            
            else{
                current_internal_node_degree += 1;
            }
        }
        i_value_partition_one[x] = current_internal_node_degree;
        
    }
    /*
    //printing i values of partition 1
    cout<<endl<<"Displaying i values of nodes in partition 1 iteration 1"<<endl;
    for(int i = 0; i < len_partition_one; i++){
        cout<<partition_one[i]<<" has ivalue of "<<i_value_partition_one[i]<<endl; 
    }
    */
    //Computing D values of partition 1 iteration 1
    for(int i = 0; i< len_partition_one; i++){     
        d_value_partition_one[i] = e_value_partition_one[i] - i_value_partition_one[i];
        D_VALUE_partition_one.insert(make_pair(partition_one[i],d_value_partition_one[i]));    
    }
    /*
    //Printing d values of partition 1 iteration 1
    cout<<endl<<"D values of nodes in partition 1 iteration 1 are as follows"<<endl;
    for(D_VALUE_partition_one_iterator = D_VALUE_partition_one.begin(); D_VALUE_partition_one_iterator != D_VALUE_partition_one.end(); D_VALUE_partition_one_iterator++){
        cout<<"Node "<<D_VALUE_partition_one_iterator->first<<" has d value of "<<D_VALUE_partition_one_iterator->second<<endl;
    }
    */

    float e_value_partition_two[len_partition_two];
    float i_value_partition_two[len_partition_two];
    float d_value_partition_two[len_partition_two];

    //Computing e values of partition 2 in fist iteration
    for(int x=0; x<len_partition_two; x++)
    {
        float current_external_node_degree = 0.0;
        string current_node = partition_two[x];
        for(int y=0; y<numObjects; y++){
            int fanout_counter = 1; 
            string current_object_string = c[y].getNodes();
            bool match_pattern_result = match_pattern(current_object_string , current_node);
            if(match_pattern_result == 1){
                for(int z = 0; z<len_partition_two; z++){
                    if(partition_two[z] == current_node){
                        continue;
                    }
                    else{
                        bool match_pattern_fanout = match_pattern(current_object_string,partition_two[z]);
                        if(match_pattern_fanout == 1){
                            fanout_counter += 1;
                        }
                        else{
                            continue;
                        }
                    }
                }
            }
            else{
                continue;
            }
            if(fanout_counter == c[y].getDegree()){
                continue;
            }
            else{
                current_external_node_degree += (float)(1/((float)fanout_counter));
            }            
        }
        e_value_partition_two[x] = current_external_node_degree;
        
    }
    
    //printing e values of partition 2
    //cout<<endl<<"Displaying e values of nodes in partition 2 iteration 1"<<endl;
    for(int i = 0; i < len_partition_two; i++){
        //cout<<partition_two[i]<<" has evalue of "<<e_value_partition_two[i]<<endl;
        initial_cut_size_partition_two += e_value_partition_two[i]; 
    }
    
    cout<<endl<<"Initial Cut-Size according to partition two"<<initial_cut_size_partition_two<<endl;


    for(int x=0; x<len_partition_two; x++)
    {
        float current_internal_node_degree = 0.0;
        string current_node = partition_two[x];
        for(int y=0; y<numObjects; y++){
            int fanout_counter = 0; 
            string current_object_string = c[y].getNodes();
            bool match_pattern_result = match_pattern(current_object_string , current_node);
            if(match_pattern_result == 1){
                for(int z = 0; z<len_partition_two; z++){
                    if(partition_two[z] == current_node){
                        continue;
                    }
                    else{
                        bool match_pattern_fanout = match_pattern(current_object_string,partition_two[z]);
                        if(match_pattern_fanout == 1){
                            fanout_counter += 1;
                        }
                        else{
                            continue;
                        }
                    }
                }
            }
            else{
                continue;
            }
            if(fanout_counter == 0){
                current_internal_node_degree += 0;
            }
            else{
                current_internal_node_degree += 1;
            }          
        }
        i_value_partition_two[x] = current_internal_node_degree;
        
    }
    /*
    //printing i values of partition 2
    cout<<endl<<"Displaying i values of nodes in partition 2 iteration 1"<<endl;
    for(int i = 0; i < len_partition_two; i++){
        cout<<partition_two[i]<<" has ivalue of "<<i_value_partition_two[i]<<endl; 
    }
    */
    //Computing D values of partition 2 iteration 1
    for(int i = 0; i< len_partition_two; i++){     
        d_value_partition_two[i] = e_value_partition_two[i] - i_value_partition_two[i];
        D_VALUE_partition_two.insert(make_pair(partition_two[i],d_value_partition_two[i]));    
    }
    
    /*
    //Printing d values of partition 2 iteration 1
    cout<<endl<<"D values of nodes in partition 2 iteration 1 are as follows"<<endl;
    for(D_VALUE_partition_two_iterator = D_VALUE_partition_two.begin(); D_VALUE_partition_two_iterator != D_VALUE_partition_two.end(); D_VALUE_partition_two_iterator++){
        cout<<"Node "<<D_VALUE_partition_two_iterator->first<<" has d value of "<<D_VALUE_partition_two_iterator->second<<endl;
    }
    */
    

    //Computing g values of the node pair in iteration 1
    for (int i = 0; i< len_partition_one; i++){
        for(int j = 0; j< len_partition_two; j++){
            string node_pair;
            node_pair = partition_one[i];
            node_pair+=partition_two[j];
            int g_value = 0;
            int conn = 0;
            for(int z = 0; z < numObjects; z++){ 
                bool result_connection_partition_one = match_pattern(c[z].getNodes(), partition_one[i]);
                if(result_connection_partition_one == 1){
                    bool result_connection_partition_two = match_pattern(c[z].getNodes(), partition_two[j]);
                    if(result_connection_partition_two == 1){
                        conn = 1;
                        break;
                    }
                    else{conn = 0;}
                }
            }
            g_value = d_value_partition_one[i] + d_value_partition_two[j] - (2*conn);
            G_VALUES.insert(make_pair(node_pair,g_value));
        }
    }

    /*
    //Printing gains of all possible pairs
    cout<<endl<<"Gains of all pairs is "<<endl;
    for(it = G_VALUES.begin(); it != G_VALUES.end(); it++){
        cout<<"PAIR "<<it->first<<" has a GAIN of "<<it->second<<endl; 
    }
    */
    


    //Finding max gain pair and value
    for(it = G_VALUES.begin(); it != G_VALUES.end(); it++){
        if(it->second > max_g_value){
            max_g_value = it->second;
            max_g_value_pair = it->first;
        }
        else{  
            continue;
        }
    }
    //cout<<endl<<"the max gain is "<<max_g_value<<" and the pair is "<<max_g_value_pair<<endl;
    gains.push_back(max_g_value);
    check_gain = max_g_value;
    gain_previous = max_g_value;
    G_VALUES.clear();
    max_g_value = -100;

    string node_of_pair_partition_one;
    string node_of_pair_partition_two;
    int temp;

    //Loop to obtain index of nodes in pair
    for(int i = 0; i< max_g_value_pair.length(); i++){
        if(i == 0)
        {continue;}
        else if(max_g_value_pair[i] == 'a' || max_g_value_pair[i] == 'p'){
            temp = i;
            break;
        }  
    }
    
    node_of_pair_partition_one = max_g_value_pair.substr(0, temp);
    node_of_pair_partition_two = max_g_value_pair.substr(temp, max_g_value_pair.length());

    //cout<<endl<<"Nodes to be locked are "<<node_of_pair_partition_one<<" and "<<node_of_pair_partition_two<<endl;

    for(int i = 0; i < final_partition_one.size(); i++){
        int position = i;
        string temp_erase_node = final_partition_one[i];
        if(temp_erase_node == node_of_pair_partition_one){
            final_partition_one.erase(final_partition_one.begin()+position);
        }
    }

    for(int i = 0; i < final_partition_two.size(); i++){
        int position = i;
        string temp_erase_node = final_partition_two[i];
        if(temp_erase_node == node_of_pair_partition_two){
            final_partition_two.erase(final_partition_two.begin()+position);
        }
    }

    locked_nodes_partition_one.push_back(node_of_pair_partition_two);
    locked_nodes_partition_two.push_back(node_of_pair_partition_one);

    for(int i = 0; i< partition_one.size(); i++){
        if(partition_one[i] == node_of_pair_partition_one){
            partition_one[i] = node_of_pair_partition_two;
            break;
        }
        else{
            continue;
        }
    }

    for(int i = 0; i< partition_two.size(); i++){
        if(partition_two[i] == node_of_pair_partition_two){
            partition_two[i] = node_of_pair_partition_one;
            break;
        }
        else{
            continue;
        }
    }

    //Updating d_value vector 
    D_VALUE_partition_one.erase(node_of_pair_partition_one);
    D_VALUE_partition_two.erase(node_of_pair_partition_two);
    /*
    cout<<endl<<"Updated Partition 1"<<endl;
    for(int i = 0; i< partition_one.size(); i++){
        cout<<partition_one[i]<<endl;    
    }

    cout<<endl<<"Updated partition 2"<<endl;
    for(int i = 0; i< partition_two.size(); i++){
        cout<<partition_two[i]<<endl;    
    }

     cout<<endl<<"Final Partition 1"<<endl;
    for(int i = 0; i< final_partition_one.size(); i++){
        cout<<final_partition_one[i]<<endl;    
    }

    cout<<endl<<"Final partition 2"<<endl;
    for(int i = 0; i< final_partition_two.size(); i++){
        cout<<final_partition_two[i]<<endl;    
    }
    */


    while(final_partition_one.size() != 1){
        //Computing d values of nodes connected to locked nodes of final partition one
        for(int i = 0; i< final_partition_one.size(); i++){
            int internal_connection = 0;
            int external_connection = 0;
            float previous_d_value;
            float updated_d_value;
            if(final_partition_one[i] != node_of_pair_partition_two){ 
                string key_one= final_partition_one[i]+node_of_pair_partition_two;
                string key_two= node_of_pair_partition_two+final_partition_one[i];
                if(connected_pairs.count(key_one) > 0 || connected_pairs.count(key_two) > 0){
                    internal_connection = 1;

                }
                else{
                    internal_connection = 0;
                }
                key_one= final_partition_one[i]+node_of_pair_partition_one;
                key_two= node_of_pair_partition_one+final_partition_one[i];
                if(connected_pairs.count(key_one) > 0 || connected_pairs.count(key_two) > 0){
                    external_connection = 1;

                }
                else{
                    external_connection = 0;
                }
                previous_d_value = D_VALUE_partition_one[final_partition_one[i]];
                updated_d_value = previous_d_value + (2*external_connection) - (2*internal_connection);
                //cout<<"Previous d_value -> "<<previous_d_value<<"Updated d_value -> "<<updated_d_value; 
                D_VALUE_partition_one[final_partition_one[i]] = updated_d_value;

            } 
        }
        /*
        cout<<endl<<"The d value of parition one is "<<endl;
        for(D_VALUE_partition_one_iterator = D_VALUE_partition_one.begin(); D_VALUE_partition_one_iterator != D_VALUE_partition_one.end(); D_VALUE_partition_one_iterator++){
        cout<<"Key is "<<D_VALUE_partition_one_iterator->first<<" value is "<<D_VALUE_partition_one_iterator->second<<endl;
        }
        */

        //Computing d values of nodes connected to locked nodes of final partition two
        for(int i = 0; i< final_partition_two.size(); i++){
            int internal_connection = 0;
            int external_connection = 0;
            float previous_d_value;
            float updated_d_value;
            if(final_partition_two[i] != node_of_pair_partition_one){ 
                string key_one= final_partition_two[i]+node_of_pair_partition_one;
                string key_two= node_of_pair_partition_one+final_partition_two[i];
                if(connected_pairs.count(key_one) > 0 || connected_pairs.count(key_two) > 0){
                    internal_connection = 1;

                }
                else{
                    internal_connection = 0;
                }
                key_one= final_partition_two[i]+node_of_pair_partition_two;
                key_two= node_of_pair_partition_two+final_partition_two[i];
                if(connected_pairs.count(key_one) > 0 || connected_pairs.count(key_two) > 0){
                    external_connection = 1;

                }
                else{
                    external_connection = 0;
                }
                previous_d_value = D_VALUE_partition_two[final_partition_two[i]];
                updated_d_value = previous_d_value + (2*external_connection) - (2*internal_connection);
                D_VALUE_partition_two[final_partition_two[i]] = updated_d_value;

            } 
        }
        /*
        cout<<endl<<"The d value of partition two is "<<endl;
        for(D_VALUE_partition_two_iterator = D_VALUE_partition_two.begin(); D_VALUE_partition_two_iterator != D_VALUE_partition_two.end(); D_VALUE_partition_two_iterator++){
        cout<<endl<<"Key is "<<D_VALUE_partition_two_iterator->first<<" value is "<<D_VALUE_partition_two_iterator->second<<endl;
        }
        */
        
        //Computing G values
        for (int i = 0; i < final_partition_one.size(); i++){            
            for(int j = 0; j < final_partition_two.size(); j++){                
                string node_pair;
                node_pair = final_partition_one[i];
                node_pair+=final_partition_two[j];
                int g_value = 0;
                int conn = 0;
                for(int z = 0; z < numObjects; z++){                  
                    bool result_connection_partition_one = match_pattern(c[z].getNodes(), final_partition_one[i]);                    
                    if(result_connection_partition_one == 1){
                        bool result_connection_partition_two = match_pattern(c[z].getNodes(), final_partition_two[j]);                        
                        if(result_connection_partition_two == 1){
                            conn = 1;
                            break;
                        }
                        else{conn = 0;}
                    }
                    
                }
                g_value = D_VALUE_partition_one[final_partition_one[i]] + D_VALUE_partition_two[final_partition_two[j]] - (2*conn);

                G_VALUES.insert(make_pair(node_pair,g_value));
                
            }
        }

        max_g_value = -100;
        max_g_value_pair = "";
        for(it = G_VALUES.begin(); it != G_VALUES.end(); it++){
            //cout<<it->first<<" : "<<it->second<<endl;
            if(it->second > max_g_value){
                max_g_value = it->second;
                max_g_value_pair = it->first;
            }
            else{  
                continue;
            }
        }
        G_VALUES.clear();
        //cout<<endl<<"the max gain is "<<max_g_value<<" and the pair is "<<max_g_value_pair<<endl;
        gains.push_back(max_g_value);
        check_gain+= max_g_value;

        for(int i = 0; i< max_g_value_pair.length(); i++){         
            if(i == 0)
            {continue;}
            else if(max_g_value_pair[i] == 'a' || max_g_value_pair[i] == 'p'){
                temp = i;
                break;
            }  
        }
        
        node_of_pair_partition_one = max_g_value_pair.substr(0, temp);
        node_of_pair_partition_two = max_g_value_pair.substr(temp, max_g_value_pair.length());
        //cout<<"The locked nodes are "<<node_of_pair_partition_one<<" and "<<node_of_pair_partition_two<<endl;

        for(int i = 0; i < final_partition_one.size(); i++){
            int position = i;
            string temp = final_partition_one[i];
            if(temp == node_of_pair_partition_one){
                final_partition_one.erase(final_partition_one.begin()+position);
            }
        }

        for(int i = 0; i < final_partition_two.size(); i++){
            int position = i;
            string temp = final_partition_two[i];
            if(temp == node_of_pair_partition_two){
                final_partition_two.erase(final_partition_two.begin()+position);
            }
        }

        locked_nodes_partition_one.push_back(node_of_pair_partition_two);
        locked_nodes_partition_two.push_back(node_of_pair_partition_one);  

        for(int i = 0; i< partition_one.size(); i++){
            if(partition_one[i] == node_of_pair_partition_one){
                partition_one[i] = node_of_pair_partition_two;
                break;
            }
            else{
                continue;
            }          
        }

        for(int i = 0; i< partition_two.size(); i++){
            if(partition_two[i] == node_of_pair_partition_two){
                partition_two[i] = node_of_pair_partition_one;
                break;
            }
            else{
                continue;
            }            
        }

        D_VALUE_partition_one.erase(node_of_pair_partition_one);
        D_VALUE_partition_two.erase(node_of_pair_partition_two);

    }
   

    int final_max_gain;
    int temp_gain = gains[0];
    for(int i = 1; i < gains.size(); i++){
        int temp = temp_gain;
        temp_gain += gains[i];
        if(temp_gain > temp){
            continue;
        }
        else{
            final_max_gain = temp;
            break;
        }
    }

    cout<<endl<<"Final max gain is "<<final_max_gain<<endl;
    cout<<endl<<"Intial Cut-size is "<<initial_cut_size<<endl;
    cout<<endl<<"Final Cut-size is "<<initial_cut_size-final_max_gain<<endl;

    

return 0;
}