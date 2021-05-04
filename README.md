# Great-project-1-course

## UML

### Object diagram

Для создания UML схем мы использовали Object diagram. Если на простом примере, то это выглядело так:

![UML model](http://www.plantuml.com/plantuml/png/LLDRRjD05FttAYxvRYBO07GhXLgYYAI86b25aE8On8UB8Yf-ArQ0v4nTcAP-RE7CZZX7eqbIHPRZE_VSyvYPuulYv7tnOVusEt_v9dzLsFooUFqqVPoUvUbl_Z5V5C_IrwUpHPRDJzx5TlkSuJhK1XTAtF7nU0XNw4EDUyDF3BWr_C8TMZoWmJrwbfoUi6Ir2slyOtqRbaGuD675AYSSMQWCAfIckM4LhWoZG6W9w1D5IsGbacjuWXk2rxFiIvH84n9umxAW3PoM-IivBLHXnUA0ph0rBME38NoNB9AB4mFxgoEveqK97SbRqOhN2CCGDKLBxSpmHo339jJoQ-XbXyz89slEH4StIxdPYOpnIkU11Ojp2M1f5uGJF0gZV4aLawH-4xzwPQmKhvUldXh2Lpd5HcPenUDMNjMPI5OiEWi_i6LFhqJW8mlSpDB-rXWrGgErImdC72YYihrw-1V96m-BZ2cLvY0L1wNYnHVJaL2QJkAU67vhj1PZXdnHWKoN62FQzYT7PjHGggyzF6sXJhldLDwtJKsQgC1RFAOqUeD1y0P_sR1Ru7SNHGpOfA3HgTUZLuSmfXn9KBEZsUrll2FJwVHvkaNn5KkJo_nYeemULnVd4zFrEyuNfxoU_m40)

Это было удобно с точки зрения кода, ведь можно отдельно создать блоки, а затем соединить их стрелочкими в нужном порядке:

```uml
@startuml

object myth0
object die
object event1
object win

map myth0 {
Вы всесильный Бог Дедлайнововремязакрыватель, у вас есть преданный друг Виталя.
}

map die {
Направляясь утром к рабочему столу, вы запнулись о провод. Это была нелепая смерть.
}

map event1 {
Виталя просит вас вместо учебы сходить с ним на футбол, играть против экономистов. Вы выполните просьбу Витали?
}

map win {
Эта была великолепная игра! После нее вы успели закрыть все дедлайны, вы ведь все - таки Бог. Но даже и Богам необходимо иногда отдыхать.
}

myth0 ---> event1
event1 ---> "yes" win
event1 ---> "no" die

@enduml
```

Это соотносится с тем, как данные представлены в json:

```json
{
  "plot_title": "Миф Нулевой",
  "declaring_character": "Вы всесильный Бог Дедлайнововремязакрыватель, у вас есть преданный друг Виталя.",
  "events": {
    "event1": {
      "is_end": false,
      "text": "Виталя просит вас вместо учебы сходить с ним на футбол, играть против экономистов. Вы выполните просьбу Витали?",
      "routes": {
        "yes": {
          "next_event": "win",
          "resource_change": {
            "determination": 10
          }
        },
        "no": {
          "next_event": "die",
          "resource_change": {
            "determination": -10
          }
        }
      }
    },
    "die": {
      "is_end": true,
      "text": "Направляясь утром к рабочему столу, вы запнулись о провод. Это была нелепая смерть."
    },
    "die_determination_high": {
      "is_end": true,
      "text": "Вы погибли от рук уличного грабителя."
    },
    "die_determination_low": {
      "is_end": true,
      "text": "Вы погибли в перестрелке."
    },
    "win": {
      "is_end": true,
      "text": "Эта была великолепная игра! После нее вы успели закрыть все дедлайны, вы ведь все - таки Бог. Но даже и Богам необходимо иногда отдыхать."
    }
  },

  "resources": {
    "determination": {
      "highest_value": 100,
      "start_value": 50,
      "lowest_value": 0
    }
  }
}
```

На примере нашего первого мифа:

![UML model](http://www.plantuml.com/plantuml/png/LCVD3OGW40RG-rIn9Im_iElDLb0d4IEOwAYnUqyayztUwmz9kvnb9Tg6XKVvb4Tcqp9brhRAJjah1-NOp1TNCRWlrc0j5ETW7XPW4VQ3_M5TsvqhKKalwsMtsqWHHE7xF4Nl_Mo4M7xW1bw9UuHansHPj64D22I4M5OBrolPGzhZs9x9ArI_4UTJ5UFso4e4uYR9z4_LEQTELtU-S27IbnVsOtcPhBLiUzkMRsnbT-M5RUqkbUkoi5iRR6Ez1dPDAdFRQMnVRko-NDbGPicsoJgjkTLMDjdtvMlzqJSCzufsiCpsSbLUClsJFcyrlDU2Unk8eYM3xPAzApFBIdgbdylBYwySftHscBOIhXKOSfaht4mVWh7WGndtVFQMDJHJkgK6UwNCRDXhrJL81vYkohm1jxM4J0BJEXbj8_TLihLsxfEezcZ2h6tWyIGXboQWfGrx8qmobdthsubiQotk5AD3M01gnU10QsBlG-mFr829s5kBcEAfQWHKVW4RtdO0UF9oW8fC0_LW2-CvEVyG7pA4ORekyjRo_qpbMTG8m3jRaP-Yd2xwOFJR813IiznGdi5z1Iu3trp3c4DpIjoN1K2G1sCwKCtQ7HYmsSeLELmw9Qh7AhYjtNaDe0Rx2-knEHCDHS7g4ML21cku7mRS4BR3pKXw1478WUHXAAr5W5y8MsPO-noQEiT7exS9i2iphQQUIy-tPi0wfG4cFg3UVh0YgmFmkiTP8X_rFGEdBF0DejR5yIRnm3bxWsHIRqkeo5Ncq05Int4hDr4ltmpGZ3nDSekphtNHRWLpHN2YGlPI8BNdFiY5-xBbI8KbfCNYyrEyxm7uPsr4N_t8x0E9L6VCEiekMGN8GvVdPT48XtiEKu4392koQYf7k4a4zW0yDwTAzmYgeOh93xHDnwAym48uOBbPNIKYJEWSzOyrePQIB6sleMLoS2hGZlq9nq6Dpx1WCACC9tugry7Mxgc55cuzvkLe42nwxzse3Rvb0Q5ZjP67GXE5MAi2BI_qX0tDhOvCHo1sD64CBqnsW86G090f6Ay9Q1b64JkXNBbcuzZjotUKJMjG6nxskoGhrpGNv2TfvOacSVhfurMHER5m8nAdl0H31NlZDMP3sD4EKmV2CIg6h2nHgNflq2d2Sf60o4UzRhSgp09YJguw3hPosk84Iv9NNPxEJJZqpwBACN_BYQOuhCjCkI7SSvIuINw9nKbCHrxrlHCTDUwTKwBF7YJwBy2YAhJ9mJt5xrVbwW643kSCKDezKsTekpScZkJsiTUXD0SWmCVz2Ampv71Ont9yfiFKWYzSMP6Z8JUdzzInuz-CBJ0mFzfWU-yT1zHYdtzijMGiAgqTpc6RR7TZ_urhOGreciU9ZcrYJrpIkMxVGGfWI3fjrq3rDcSP7fhfzFSXpWU9OszPUewMAJRo5u9or4W5G9gh0pmsbjE2SV_QdqVW9FIY8CdOEWWdiY6tl149OqTOYOORx8Pu0KHzcySj8BflQvDRFkimBlFpL-NuHWqstgmUk4gjFUaQw1MlrE1HNx5ZuV_RFVfnzNRhnlCH3qBayqSynmhnMWWY5naeDQ7ToWiNpoVY1MAR-ZOyi9aFwZOMnH-jqHZW29FVB5f0mqRkX0tTV-gIJ-ALTZoCBuXRxN4ggEsLG0cO_KfIP1zVJvjusY60qQOD8O65cw29BuHjT2NRj2pkqYZ4UADgvMle4RVZkLl3S2cnxIQEJ_qEdag0QyCR3wdnwQZ6lBvLY3XzO89fVBdGMki7X97-7I3zAFl_3Rqh0Pc1jodGmgBvoSWwdc9eEuBJ_vtrUo3UpbjRDuceg3kjOCWVEO3F02TnMvux8SOUAvw2li91WkzoiAzbrF-_0GXACb9LwXBa_a_oqwUV_VD0leZVVzTTxZO8m30GxHaZ4yIOVD8n3EaW58Y2xP752N67qZu_dModYGEbrtma_0E8hpkm0-SVF-wABsRT30LZln8EFzO9UDHU1XV2ZjFhG__i0YwjGFUDxfIDwKygLt2ICMDHkH7dvAgo4-Vafd8d3Xa9VREzha-3JeRwbb6GRH_ESrsUj-iR)

### Activity diagram

Нам посоветовали использовать Activity diagram. Принятие решений действительно яыляются некоторой сюжетной развилкой, это выглядело бы так:

![UML model](http://www.plantuml.com/plantuml/png/JLDDRjDW4Dr_fnXsgLHwWBAWLq4Y5PLAYaXOi8jhAXOfYgZO8aw0v7oDmKaSvmflRiHxOyL1aMLxlfatxoU-cixUV9nzUd-RuY5TuiaNXkm5QbuDTlw8lI-mCNn7XsV33zHOOuSA6-nPohfypchhI_nbVUjpJcHKVezQ2EV9lBIe52PWl_T7mo6crfpO7tUiELfgonCQJbUSNbwyIZVNDah_r_hXpWkL1kICjaT7nuN-bUWhoc7b0HqNDR5NdNjAQtMhpBzuoOaLEtOaoeDdGbSdYXrF6sJpRzYY2yqjcduDyaMoesSB70GYS2aVEDB2bVGF_D6yJcSsUpUUsEZpU7gMp2xnMsScmZ9NOcfrniuTdmzYwyk1u0lZvb_2rx6qrBo9XhGNx8zvEqKIalfiwVGfHfalvJbag3xqlGp2My54_5Bxa-v6Qd-8CvpmlGqIV5aT_KQhtePbTN36miqrkJpq5ZFSyUrqRAF9NTX0z2fygv0LD7_qpnIHpDIEhUbOWKN2BQtjms1_UHuoGhGSyr8U18IOH2388YSbihmxMHxim-emseluEysFD2TlRwxvcTnzI5TyvZVp3m00)

Но для людей, незнакомых с условными обозначениями, и для нашего первого мифа это выглядело бы сложно. В один и тот же блок может вести несколько событий, не знаю, как это выглядело бы со строны кода. Код для прошлого примера:

```uml
@startuml
start
:Вы всесильный Бог Дедлайнововремязакрыватель,
 у вас есть преданный друг Виталя.;
if (
Виталя просит вас вместо учебы сходить с ним на футбол,
 играть против экономистов.
 Вы выполните просьбу Витали?
) then (yes)
  :Эта была великолепная игра! 
 После нее вы успели закрыть все дедлайны,
 вы ведь все-таки Бог.
 Но даже и Богам необходимо иногда отдыхать.;
else (no)
  :Направляясь утром к рабочему столу, вы запнулись о провод.
 Это была нелепая смерть.;
endif
stop
@enduml
```

События не разделены на блоки, их нужно прописывать сразу. Если мы захотим, например, для каждого события прописать изменения ресурсов, то это потребует больших изменений и будет выглядеть запутанно. Мы решили остановиться все-таки на Object diagram
