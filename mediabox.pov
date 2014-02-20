    // Grundgerüst
#include "colors.inc"
#include "textures.inc"
#include "mediabox_object.inc"
#include "tisch_object.inc"
#include "tafel_object.inc"
#include "geruest_object.inc"

global_settings {
    assumed_gamma 1.0
}
camera {
    // Nahaufnahme der Multimediabox
    //location <0,125,-130>
    //look_at  <0,111,0>
    
    // Interessante Kameraposition
    //location <-40,130,-130>
    //look_at  <0,100,0> 

    // umfassende Ansicht des modellierten Ausschnittes   
    location <-20,300,-450>
    look_at  <0,50,200>
}

// kein Himmel, da der Messestand geewöhnlich in einer Halle steht
 
 
// Eine graue Ebene, der Boden der Messehalle  
plane {
    y, 0
    pigment {
        Grey    
    }
}

//light_source{ <-165,300,-165> color rgb <1,1,1> }
//light_source{ <165,300,-165> color rgb <1,1,1> }

// Bühne 3,5x3,5m
#declare buehne = box {
                        <-175,0,-175>,<175,10,175> 
                        pigment {Yellow}
                  }

// Einzelne Objekte zusammenbauen
object { mediabox translate<-20,123,-100> }
object { tisch translate<-0,10,-100> }
object { buehne }
object { tafel translate<0,0,50>} 
object { geruest }
object{ scheinwerfer }

