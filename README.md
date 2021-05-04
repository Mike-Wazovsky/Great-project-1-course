# Great-project-1-course

## UML

### Object diagram

Для создания UML схем мы использовали Object diagram. Если на простом примере, то это выглядело так:

![UML model](http://www.plantuml.com/plantuml/png/RLDDRjDW5Dpx58-icqgv0FGg1R91j4KqB112gkCY5WwAg5WI8Gw0zCMDgPlOpXNctQWp-cJ7aUgDfVTcvitx-SwkP-SVPvyktYTNhzzDtymClr7vBLQUOOSI1LeyThb93_gB6gNV-DmNVUmFeMjIDWX9Sd7-uLaf-v8OxZmt59vI8aM5dI_GUCuaVX9pR_Wb6P827j6W5PNu6qPhN-A1yIsBvum7dwEKmabYdXaKIKt2ycROYoLBQBeQ6r8pLRb3HNOWUtcQV8sU9p8up4I9rbE5Ulq2TQo1bcNzEskisHGZtz1YGwog2zcWGgrVCBybT8ur4JlQPUAUqk5Wj6MsGc7-0rk2r7cDAfP1SNgON8wzH2Ik_dkFlg2DRE0VrQkki-7Er2HM18WNKAXHNufliYWncTwQqZAi3b5JEfeXFZin6J4yI0QDbYolwgMDXkBUDlBzJopJZBHLZQFKJP0OV4dHWxL-4yDxej-e4GOQXJHGQLHH2utK-hc-iCGaugdIiMOPJNl6u3xoxN1FgYz0AjncU8EUQs6Yeb2ynurzBZPbuksgsHLQqGF-KwVF8A2E9jXMToQeXQqO5aATwWYednCH-day-vB6uvTyaHFzRNHvDJhQS1V_FBqU7J_Di-dbMxttu-y9)

Это было удобно с точки зрения кода, ведь можно отдельно создать блоки, а затем соединить их стрелочкими в нужном порядке:

```uml
@startuml
object МифНулевой
object 1
object Смерть
object Победа

map МифНулевой {
 Вы всесильный Бог Дедлайнововремязакрыватель,
 у вас есть преданный друг Виталя.
}

map 1 {
 Виталя просит вас вместо учебы сходить с ним на футбол,
 играть против экономистов.
 Вы выполните просьбу Витали?
}

map Смерть {
 Направляясь утром к рабочему столу, вы запнулись о провод.
 Это была нелепая смерть.
}

map Победа {
 Эта была великолепная игра! 
 После нее вы успели закрыть все дедлайны,
 вы ведь все-таки Бог.
 Но даже и Богам необходимо иногда отдыхать.
}

МифНулевой --> 1
1 --> "no" Смерть
1 --> "yes" Победа
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

![UML model](http://www.plantuml.com/plantuml/png/j9VBRXpL4yRtVegJ_Vn7SMpdilhpAW6nGKGW22k4v9ac5pGc0mWaX1AYm3fIJsTEtFPCjr-XpXjHFrNNcHEcvMJ38ahFkLHztrUNElxewuVtlthupOFF3xxu-BDFFtaOvBcqwNjvAJ6TIfCMSk4xX_vnop-E_EFOFqxyuxP_tF6Fk_vnBnkycRyEyrSsBgza2uWqJsU7OukZ9u_65e_75a_65ZDi5Q2NbKHPItrmyE3-boF2X6yFWloI5a4QFRZHxITIoqLwAgrkfaUfqjkzl9LE5oud8StaKjSswKokqbpwT1ga3NAkPzPwbKloaxfefPkmt4aDCguhDXpAhuP8DdhWIdgiw95UBeEyLbXHdSubfkN1TmRwq31AhQ1g0CGqKrkd-cDWiWORFw_qHvzc-8BGULeYYDvHpvrTRjHJb3VIg_U_GC6zHg_2G77K6CTgEalBQL3Fl-ijTZUGO2-eWPYTgHAhLFtVqTxQeSNeHizkqr8w4p1W7QyXLIfNj5K42B9MdnN8-1TAA59FK5dnHV1AXDuAI0gII4Kr1qh4a_Q60dY5hC3bO6GFXMr9BytIKcFvX4E333WapchRg4K4rAMBDCTt0vpCykXQbX-Er78KpjW_rGFy_opDhq5dK4P0JWT8in7E8Vs8kKpW60BoOj2ubiQHDt2o31bX9ZL9pV5MuxNWDE3i-8uPIK_80X3XBGHSLgP-JhpfX-Pr9v43MxJYelre4Sp3gKjUJboDSf7J7Y1q0b1BfsHA5Pl07TmeiLXKZRC267hkLmbkg1E9HgJNgsTKknK9dkroMfgJXYrkyeMar0--GAZOpa7eLKPbvN2T42xvUuSQPnOIg-1jMgGPMHPWEeWj5-vik65PX5-driiL93owa_Sd05nVbGakyT_9THkquxq9F2qt1ohJ87zATqtlakRTLa4fMkDr4aLFoo6VVd3V2Wxw3g2zViwzC1W9O40vQ-HfRherq4CfmVpIx5eAL-Zc6pTymBoLjSirysabaPXvGCn6Q_q0YaRakPS-uuTKr5yrucJ1x-OnbclmAKRpUIU2qXO5H83N7tX4yjQyuweL3aDVwCje22OXZI19GapBVEIUhBb7AGvHq0WG-NJAqHSA1ijaRJehWPYK2XoEWGrcB377tfu2PAoFjN4nxhaO72YdYD5IswTfWUoA543As-iOGGWto3pNNmFHwjUU1vqfeJSfDVJGBKlFIB07ra4sx21kXdPu4spoMvfXoqz4I_GLQshq4dTCIilTz3XLaum9gM5aoTcYY4GpjsU1E-JSP8YilJBKOfNccRH5ykTK5Ta9Bi9fkBGMXeXYOiUbU9SC-zuVwR6U2K1AJtt6DxGfcqgJKcfBY38qwT50bLgoYMCsfuN4L9fDe6PWcogZOxqaDzA07Qn9NVJs7HTUBQLPqjGCzzuHMqMKsopmh3yoLp0MuJFOjVxnY8lUxgn5CehGsLXeumjwggUxqLMgCXyc55vjDU41HZwlcfgXwFImzj82p0rlTjlYNLQ-aAzxKLxHGJ9gd5XJekQaIuiXGLB5-oNBC_DeaWnIvnPj0U0DH5oXs553x09KkXkvRncyt6yvzuFTnpGgotbQC2CDBkbeICSe4b1_EvKl9HesItcEGW05XWUBJHdmbU-so7hqzcov0IqVbiLV3tI1_uhKKJcYxCK2tCtuwUFS1ot5fBCwwD_fhotvGoBxy4nL-N3Z1Bl-3YQpJQJjrAqJMuxb5zvY0Zn6cgQmTHhCeJAeEKkgiZW6_CI1c-guj5TL0OSo0yQGTuWzomLC9Op16dDsUrSBUyC1noiMzEiDm2tTxKa19dDlIDvfiZYsBDW7HllbIghAo9L_h9RDoDcsifgW1mZsvhmFQPj4a6O1dcrwRAf9-_uHhqQVJKY39yFKv5x3gcKhG6Xfh1JJ70eZVrd_xvywx1q5eHY8md1_LX7I2pcJToCknjlfjH0BToy88JEGL27yNpBzNAwEuF_qvyix6PVlyVOkGcPA49KoqansXv0KAoWxLioWk6Q2Q8Rc7SkALTGrYwYADRJ9A6YgTL3MVwHH1kmxrnLZ0CE491XKjWiJSagp824tRmfkntd_F1y_)

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
