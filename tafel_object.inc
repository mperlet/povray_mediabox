
#declare tafel = union {
    cylinder {<40,10,40>,<40,220,40>,2.5 pigment {Candy_Cane}}
    cylinder {<40,10,310>,<40,220,310>,2.5 pigment {Candy_Cane}} 
    box{<40,70,40>,<41,190,310> 
        pigment { White_Wood }
    }
}

// Poster für Aufgabe 6
#declare bild = plane { 
    y, 1
    texture { 
        pigment {
            image_map { 
            png "mediabox_front.png"
            map_type 0
            once
            }
        scale <30,30,1>
        rotate -90*x
        }
    } 
}

// Bilderrahmen für das Poster
#declare bilderrahmen = union {
    //links
    cylinder {<0,0,0>,<0,50,0>,2}
    //rechts
    cylinder {<100,0,0>,<100,50,0>,2}
    //oben
    cylinder {<-1,50,0>,<101,50,0>,2}
    //unten
    cylinder {<-1,0,0>,<101,0,0>,2}
}

// fügt das Poster mit dem Rahmen zusammen
#declare bild_mit_rahmen = union {
    object { bild scale<3.4,1,1.6> rotate<90,0,0> }
    object { bilderrahmen texture { EMBWood1 } }
}

// fügt die Tafel mit dem Bild zusammen
#declare tafel = union {
    object { bild_mit_rahmen translate<0,115,7> }
    object { tafel rotate<0,90,0> translate<-175,0,50>}
}
