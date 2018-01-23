#include "polygons.h"
#include "utilities.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//this function first gets the distance of each side and compares too the initial disance and returns true if theyre all the same
bool Polygon::HasAllEqualSides(){
    vector <double> sames;
    for (int i = 0; i< vertices.size()-1; i++){
        sames.push_back(DistanceBetween(vertices[i],vertices[i+1]));
    }
    sames.push_back(DistanceBetween(vertices[vertices.size()-1],vertices[0]));
    for (int i = 0; i<sames.size(); i++){
        if (! EqualSides(sames[0], sames[i])){
            return false;
        }
    }
    return true;
}
//similar to has all eaqual sides but instead of sides its angles so gets angles then comapres all of them together 
bool Polygon::HasAllEqualAngles(){
    vector <double> sames;
    for (int i = 0; i< vertices.size()-2; i++){
        try{
            sames.push_back(Angle(vertices[i],vertices[i+1],vertices[i+2]));
            
        }
        catch(string){
            throw 3;
        }
    }
    try{
        sames.push_back(Angle(vertices[vertices.size()-2],vertices[vertices.size()-1],vertices[0]));
        sames.push_back(Angle(vertices[vertices.size()-1],vertices[0],vertices[1]));
    }
    catch (string){
        throw 3;
    }
    

    for (int i = 0; i<sames.size(); i++){
        if (! EqualAngles(sames[0], sames[i])){
            return false;
        }
    }
    return true;
}
//goes through all the angles of the shape and returns true if there is a right angle in it
bool Polygon::HasARightAngle(){
    vector <double> sames;
    for (int i = 0; i< vertices.size()-2; i++){
        try{
            sames.push_back(Angle(vertices[i],vertices[i+1],vertices[i+2]));
        }
        catch(string){
            throw 3;
        }
    }
    try{
        sames.push_back(Angle(vertices[vertices.size()-2],vertices[vertices.size()-1],vertices[0]));
        sames.push_back(Angle(vertices[vertices.size()-1],vertices[0],vertices[1]));
    }
    catch(string){
        throw 3;
    }
    for (int i = 0; i<sames.size(); i++){
        if (RightAngle(sames[i])){
            return true;
        }
    }
    return false;
}
//like has a right angle, returns true if there is an obtuse angle in the shape
bool Polygon::HasAnObtuseAngle(){
    vector <double> sames;
    for (int i = 0; i< vertices.size()-2; i++){
        try{
           sames.push_back(Angle(vertices[i],vertices[i+1],vertices[i+2]));
        }
        catch(string){
            throw 3;
        }
    }
    try{
        sames.push_back(Angle(vertices[vertices.size()-2],vertices[vertices.size()-1],vertices[0]));
        sames.push_back(Angle(vertices[vertices.size()-1],vertices[0],vertices[1]));
    }
    catch(string){
        throw 3;
    }
    
    for (int i = 0; i<sames.size(); i++){
        if (ObtuseAngle(sames[i])){
            return true;
        }
    }
    return false;
}
//like right and obtuse angle it returns true if theres an acute angle 
bool Polygon::HasAnAcuteAngle(){
    vector <double> sames;
    for (int i = 0; i< vertices.size()-2; i++){
        try{
            sames.push_back(Angle(vertices[i],vertices[i+1],vertices[i+2]));
        }
        catch(string){
            throw 3;
        }
    }
    try{
        sames.push_back(Angle(vertices[vertices.size()-2],vertices[vertices.size()-1],vertices[0]));
        sames.push_back(Angle(vertices[vertices.size()-1],vertices[0],vertices[1]));
    }
    catch(string){
        throw 3;
    }
   
    for (int i = 0; i<sames.size(); i++){
        if (AcuteAngle(sames[i])){
            return true;
        }
    }
    return false;
}
//function checks to make sure that only two sides are the same length and returns true if 2 sides are congruent and false if theres 3 or all congruent 
bool Polygon::HasOnlyTwoEqualSides(){
    vector <double> sames;
    for (int i = 0; i< vertices.size()-1; i++){
        sames.push_back(DistanceBetween(vertices[i],vertices[i+1]));
    }
    sames.push_back(DistanceBetween(vertices[vertices.size()-1],vertices[0]));
    if(EqualSides(sames[0], sames[1]) && !EqualSides(sames[0], sames[2])){
        return true;
    }
    if(EqualSides(sames[0], sames[2]) && !EqualSides(sames[0], sames[1])){
        return true;
    }
    if(EqualSides(sames[1], sames[2]) && !EqualSides(sames[1], sames[3])){
        return true;
    }
    
    
    if(EqualSides(sames[0], sames[1]) && EqualSides(sames[0], sames[2])){
        return true;
    }

    return false;
    
}
//checks to make sure that the top and bottom sides of shape are the same length and returns true if so
bool Polygon::baseAndTopSame(){
    if (EqualSides(DistanceBetween(vertices[0], vertices[1]), DistanceBetween(vertices[2],vertices[3]))){
        return true;
    }
    if (EqualSides(DistanceBetween(vertices[3], vertices[0]),DistanceBetween(vertices[1],vertices[2]))){
        return true;
    }
    if (EqualSides(DistanceBetween(vertices[2], vertices[3]),DistanceBetween(vertices[0],vertices[1]))){
        return true;
    }
    if (EqualSides(DistanceBetween(vertices[1], vertices[2]),DistanceBetween(vertices[3],vertices[0]))){
        return true;
    }
    return false;
    
}
//checks to make sure both opposite angles are the same 
bool Polygon::OppositeAngles(){
    try{
        if(EqualAngles(Angle(vertices[0], vertices[1],vertices[2]),Angle(vertices[2], vertices[3],vertices[0])) && EqualAngles(Angle(vertices[2], vertices[3],vertices[0]),Angle(vertices[0], vertices[1],vertices[2]))){
            return true;
        }
        return false;
    }
    catch(string){
        throw 3;
    }
    
}
//checks to make sure angle inbetween congruent sides is the same as the oppoiste angle
bool Polygon::MiddleAngle(){
    if (EqualSides(DistanceBetween(vertices[0], vertices[1]), DistanceBetween(vertices[1],vertices[2]))){
        try{
            if (EqualAngles(Angle(vertices[0], vertices[1],vertices[2]),Angle(vertices[2], vertices[3],vertices[0]))){
                return true;
            }
            return false;
        }
        catch(string){
            throw 3;
        }
    }
    if (EqualSides(DistanceBetween(vertices[1], vertices[2]), DistanceBetween(vertices[2],vertices[3]))){
        try{
            if (EqualAngles(Angle(vertices[1], vertices[2],vertices[3]),Angle(vertices[3], vertices[0],vertices[1]))){
                return true;
            }
            if (EqualAngles(Angle(vertices[2], vertices[3],vertices[0]),Angle(vertices[0], vertices[1],vertices[2]))){
                return true;
            }
            if (EqualAngles(Angle(vertices[3], vertices[0],vertices[1]),Angle(vertices[1], vertices[2],vertices[3]))){
                return true;
            }
            if (EqualAngles(Angle(vertices[0], vertices[1],vertices[2]),Angle(vertices[2], vertices[3],vertices[0]))){
                return true;
            }
            return false;
        }
        catch(string){
            throw 3;
        }
    }
    if (EqualSides(DistanceBetween(vertices[2], vertices[3]), DistanceBetween(vertices[3],vertices[0]))){
        try{
            if (EqualAngles(Angle(vertices[2], vertices[3],vertices[0]),Angle(vertices[0], vertices[1],vertices[2]))){
                return true;
            }
            return false;
        }
        catch(string){
            throw 3;
        }
    }
    if (EqualSides(DistanceBetween(vertices[3], vertices[0]), DistanceBetween(vertices[0],vertices[1]))){
        try{
            if (EqualAngles(Angle(vertices[3], vertices[0],vertices[1]),Angle(vertices[1], vertices[2],vertices[3]))){
                return true;
            }
            return false;
        }
        catch(string){
            throw 3;
        }
    }
    return false;
}
//checks to make sure if either side is Parallel with the other and reutrns true if two sides are congruent
bool Polygon::ParaLSides(){
    try{
        Vector one(vertices[0],vertices[1]);
        Vector two(vertices[1],vertices[2]);
        Vector three(vertices[2],vertices[3]);
        Vector four(vertices[3],vertices[0]);
        if (Parallel(one,three)){
            return true;
        }
        if (Parallel(two,four)){
            return true;
        }
        return false;
    }
    catch(string){
        throw 3;
    }

}
//checks to make sure all angles are reflex angles if so then return false, else it is a convex shape 
bool Polygon::IsConvex(){
    vector <double> sames;
    for (int i = 0; i< vertices.size()-2; i++){
        try{
            sames.push_back(Angle(vertices[i],vertices[i+1],vertices[i+2]));

        }
        catch(string){
            throw 3;
        }
    }
    
    try{
     sames.push_back(Angle(vertices[vertices.size()-2],vertices[vertices.size()-1],vertices[0]));
    sames.push_back(Angle(vertices[vertices.size()-1],vertices[0],vertices[1]));
    }
    catch(string){
        throw 3;
    }
    
   
    for (int i = 0; i<sames.size(); i++){
        if (ReflexAngle(sames[i])){
            return false;
        }
    }
    return true;
    
}
//just like is convex, and just says if its not convex its a concave shape
bool Polygon::IsConcave(){
    return !(this->IsConvex());
}
//for isoloses triangle it checks to make sure its base angles are the same and if not returns false 
bool Polygon::bottomSame(){
    try{
        if(EqualAngles(Angle(vertices[3],vertices[0],vertices[1]),Angle(vertices[2],vertices[3],vertices[0]))){
            return true;
        }
        return false;
    }
    catch(string){
        throw 3;
    }

}
//checks to make sure two sides are the same for arrows and returns true if theyre the same 
bool Polygon::sameDistanceArrow(){
    if(EqualSides(DistanceBetween(vertices[2],vertices[3]),DistanceBetween(vertices[3],vertices[0]))){
        return true;
    }
    if(EqualSides(DistanceBetween(vertices[1],vertices[2]),DistanceBetween(vertices[2],vertices[3]))){
        return true;
    }
    return false;
}
