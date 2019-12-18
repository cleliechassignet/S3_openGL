#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>
#include <string>
#include <iostream>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl.h>
#include <imgui/imgui_impl_opengl3.h>

#include "menu.hpp"
#include "cube.h"

std::string current_color_string="Violet";

static bool rouge=false;
static bool orange=false;
static bool jaune=false;
static bool vert=false;
static bool bleu=false;
static bool indigo=false;
static bool violet=false;

void afficheMenu(unsigned int curseur, glm::vec4* current_color, Cube stockCube[],unsigned int l,unsigned int L) {
    //création du menu
    ImGui::Begin("Menu");

    //Menu couleurs
    if (ImGui::BeginMenu("Couleur : "))
    {
        ImGui::MenuItem("Rouge", NULL, &rouge);
        ImGui::MenuItem("Orange", NULL, &orange);
        ImGui::MenuItem("Jaune", NULL, &jaune);
        ImGui::MenuItem("Vert", NULL, &vert);
        ImGui::MenuItem("Bleu", NULL, &bleu);
        ImGui::MenuItem("Indigo", NULL, &indigo);
        ImGui::MenuItem("Violet", NULL, &violet);
        ImGui::EndMenu();
    }

    ImGui::Text("%s", current_color_string.c_str());

    if (rouge==true){
        *current_color = glm::vec4(1.0f, 0.0f, 0.0f, 0.8f);
        if(stockCube[curseur].isVisible==true) stockCube[curseur].color= *current_color;
        current_color_string="Rouge";
        rouge=false;
    }
    if (orange==true){
        *current_color = glm::vec4(1.0f, 0.6f, 0.0f, 0.8f);
        if(stockCube[curseur].isVisible==true) stockCube[curseur].color= *current_color;
        current_color_string="Orange";
        orange=false;
    }
    if (jaune==true){
        *current_color = glm::vec4(1.0f,0.89f, 0.2f, 0.8f);
        if(stockCube[curseur].isVisible==true) stockCube[curseur].color= *current_color;
        current_color_string="Jaune";
        jaune=false;
    }
    if (vert==true){
        *current_color = glm::vec4(0.0f,1.0f, 0.0f, 0.8f);
        if(stockCube[curseur].isVisible==true) stockCube[curseur].color= *current_color;
        current_color_string="Vert";
        vert=false;
    }
    if (indigo==true){
        *current_color = glm::vec4(0.47f,0.1f, 0.97f, 0.8f);
        if(stockCube[curseur].isVisible==true) stockCube[curseur].color= *current_color;
        current_color_string="Indigo";
        indigo=false;
    }
    if (bleu==true){
        *current_color = glm::vec4(0.0f,0.0f, 1.0f, 0.8f);
        if(stockCube[curseur].isVisible==true) stockCube[curseur].color= *current_color;
        current_color_string="Bleu";
        bleu=false;
    }
    if (violet==true){
        *current_color = glm::vec4(0.93f,0.5f, 0.93f, 0.8f);
        if(stockCube[curseur].isVisible==true) stockCube[curseur].color= *current_color;
        current_color_string="Violet";
        violet=false;
    }
    ImGui::Spacing();
    ImGui::Spacing();

    //Sculpture du monde : créer, supprimer, creuser et extruder

    ImGui::Text("Sculpture : ");
    ImGui::Spacing();

    if(ImGui::Button("Créer")){ 
        stockCube[curseur].isVisible=true;
        stockCube[curseur].color= *current_color;
    }
    ImGui::SameLine();
    if(ImGui::Button("Supprimer")){ 
        stockCube[curseur].isVisible=false;
    }
    if(ImGui::Button("Extruder")){
        unsigned int current_cube = curseur;
        while(stockCube[current_cube].isVisible==true) {
            current_cube=current_cube+l*L;
        }
        stockCube[current_cube].isVisible=true;
        stockCube[current_cube].color= *current_color;
    }
    ImGui::SameLine();
    if(ImGui::Button("Creuser")){ 
        unsigned int current_cube = curseur;
        while(stockCube[current_cube].isVisible==true) {
            current_cube=current_cube+l*L;
        }
        stockCube[current_cube-l*L].isVisible=false;
        stockCube[current_cube-l*L].color= *current_color;
    }

    ImGui::End();
}