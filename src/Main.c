#include "C:/Wichtig/System/Static/Library/WindowEngine1.0.h"

void Button_React(ButtonEvent* be,Button* b){
    if(be->e.EventType==EVENT_PRESSED){
        printf("Pressed.\n");
    }
    if(be->e.EventType==EVENT_RELEASED){
        printf("Released.\n");
    }
}
void Label_React(LabelEvent* be,Label* b){
    if(be->e.EventType==EVENT_PRESSED){
        printf("Pressed.\n");
    }
    if(be->e.EventType==EVENT_RELEASED){
        printf("Released.\n");
    }
}
void ProgressBar_React(ProgressBarEvent* be,ProgressBar* b){
    if(be->e.EventType==EVENT_EMTY){
        printf("Emty.\n");
    }
    if(be->e.EventType==EVENT_FULL){
        printf("Full.\n");
    }
}


Scene scene;

void Setup(AlxWindow* w){
    scene = Scene_New();
    Scene_Add(&scene,(Button[]){ Button_New("Click Me",Button_React,Font_New(FONT_BLOCKY),(Vec2){16.0f,16.0f},(Rect){ {100.0f,100.0f},{400.0f,200.0f} },ALIGN_HORI_CENTER | ALIGN_VERT_CENTER,WHITE,RED) },sizeof(Button));
    Scene_Add(&scene,(Button[]){ Button_NewStd("Click Me",Button_React,(Vec2){25.0f,25.0f},(Rect){ {200.0f,200.0f},{400.0f,200.0f} },WHITE,RED) },sizeof(Button));
    Scene_Add(&scene,(Label[]){ Label_NewStd("Label Me",Label_React,(Vec2){25.0f,25.0f},(Rect){ {300.0f,400.0f},{400.0f,200.0f} },WHITE,RED) },sizeof(Label));
    Scene_Add(&scene,(ProgressBar[]){ ProgressBar_NewStd("Bar Me",ProgressBar_React,(Vec2){25.0f,25.0f},(Rect){ {300.0f,400.0f},{400.0f,200.0f} },WHITE,BLUE,0x77FF0000,0.1f) },sizeof(ProgressBar));
}

void Update(AlxWindow* w){
    Scene_Update(&scene,window.Strokes,(Vec2){GetMouse().x,GetMouse().y});
    
    Clear(BLUE);
    Scene_Render(WINDOW_STD_ARGS,&scene);
}

void Delete(AlxWindow* w){
    Scene_Free(&scene);
}

int main(){
    if(Create("Game Test",1900,1000,1,1,Setup,Update,Delete))
        Start();
    return 0;
}