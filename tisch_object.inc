#declare tisch = union {
    
    //Tischplatte
    prism {
        0, // Startpunkt
        1, // Endpunkt
        7, // Anzahl der Eckpunkte
        <6,10>,
        <-6,10>,
        <-10,0>,
        <-6,-10>,
        <6, -10>,
        <10,0>,
        <6,10>
        pigment { Tom_Wood }
        scale <7,2,2>
        translate<0,110,0>
    }
      
    // Tischbein
    cylinder{ <0,0,0>,<0, 110,0>, 5
             texture { Silver_Metal }
          }
          
    // Tischfuß
    cylinder{ <0,0,0>,<0, 4,0>, 40
             texture { Silver_Metal }
          } 
}
