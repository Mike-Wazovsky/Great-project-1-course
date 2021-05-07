# Great-project-1-course

## Инструкция по сборке игры

Зайти в папку /build
Ввести команду "cmake ..", затем "make"
Запустить исполняемый файл: "./macaftc"

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

![UML model](http://www.plantuml.com/plantuml/png/LCTD3aKm50RGULVnbl3wqs9cAyLDLBI4YzYzKPFxpSxfJuu7NtbLsx3GoB_yygnhfaJIHjWAEs4l7Ahffi8QzyTgh87YBCp1F2p06bWBw-gUL9JASVzOBxiTDuec39_dAZhViMDz8lp02LmNGaXUcmsBOc9084M8W1QE8uq7zzgxjcTleVgEgEUTsd7RiZOHuYIRwUcgUdzggjkz4Ech9_PJUPcijMnRsvHlhR7RScKRkqtbiiniPPtTsDuNxaQfNDYThstBtExBrBeoIRP9jlOzAmybo7uet_X_zYEMzvvjPvdmCYqlUVspFwvyUUiRxgqZYs_fx2xPspAnx4Md_kzY_EHhuPH7WccDush0aCk5fvluWyEOyU0LjppkBVlInCijV77l9JC1Mzzr2T8Efasv60btIyhaO5fWA8pQqsHBZzmcfxf74u6yWSTJoSKBf-K1MwL9slPT7wxCIz-yzXnhX1N0lNKzq9hO1n3x4pMIO6Th4RDSuKP0vG-muMsx7hZi01MLElmWHFHJpp_45ndHj5oRlB7y7rDv7Xu1-CuQwcFAyQOFXtxh78JhMUROq_Lz1IuYFFbSpU7llF2-p02YvhZgT-YjtOA1DcjwHNPZ9G_t29avUdNU252T_Kth4Pp99aN1obwQaCKQxaS1LyAgaBIQ3Y2KigDuD9JlHO3Nf2qJMliSchh6nqDla-2kJ7mtVYxwUaijhBqCCEa3_8uFAweAGEzxV4lKUve4_HHEcT4tY7faZeR48z_P7v9iPHjIgHQkGGT8QpwtCW-_52oW6NaSf5gSkBONRUKm6vAJ5RBkt6kFkGzoqNtPyb2gp5sBsHV7UFyFu5yyK7PivKqM4bkoPcjiTra1fDJbHPcDWAoUewd00PA6glugHxgJ3CG0F8-EbTuZg2zLJ7xKs1IMf6GPuGGBJqCbCfpGEUWVUq8jBxAmhIyjKW_E3ReZNXq7DHwZ1OEPRAZxgLoABIhZXM_Sz3d7GuFGelVzD6g3Rvc9qE0syc0qMSZLzBHaz0aRXbkLEIRIDeQm6junsKuCjW3KAnWlbJ33A79BkN99u33jo_VOvdjGMyh_xfBv9WsNCgLerHEZnDVF7AzCRZMCeW7ssYo6OrfU7XFmq8wxqmw4OpY6hDgoy3mQq2dISf20IAlXsygDcK5CvEhFmHhHXXCiALvDUIOtwT0_SwRv6B_M5xtHFj0ZeUgevx1ubFf3BBx4TE1LdpinKUFSEIRw_36YxmzMgaAP6fnJ-lkgJ1z3A3XdW8xZm3b3Mxrnsf4wVTw4qdm00JxEHs2T8KU7hUDxMVd7r0fVRA_8DJgSwtFgCF7dmmWSl-U0tVUpOuTQnEd1SqqEflfINA4KckrscBznB2m1hU5HwzWcOkAGplNu3b80GzBJSIse6dEMnQFpo7aSYLaJ9s8Td6gql2AG_qdGJcdc0DHm5S33O3asJEVlNmVW50nJa6GO7NEH3RczDw9WH4GhCN23NHStWF1tzCuMmBRhkiajd-qm3lEpHsLzHnMRSM9OFNAKMdiqDT0hRgd1epvY1-F_tJdwINLtMm_VHrm89PykyGvGuhKGH2vLM2XrjF8inDEBk67QJNqQxWZc0Ty6KvHY4uC1ZeqBzDl321WHo9bmm_G_xP9FuvPs-1Ylo7k82IfIMqwW1Cn-fIYo3xUdcxZQ8O36D48A5jq4JVfYN7MbmbOFPsaOCPoepk8DzCYxvhfRmm241YGizQA-1sDcBG5T6xtnc1gV3MfSrASA6Kylc60QRYwCrle2eV9l0QbFENutu5TM85-SR9z6Y-Qd0-kuYg7j0Cv_TzRtWRWxRsmvIcH5tLC7G_we8VWhLgyzyOkU46llCi-JlgA37BxaK5pBgcAN0459LYgdnaAk7ydFddt-S45-4dzP-j-N_zHXnZW8n30G_0ilE6CkT-bu3DT1A13_HrP6Ghk8TZnQsKwJv7YTk0S87qzmWfUlF_yGmAP7K0Zrc-3oQvt0i_VIjL1sFRqc_R5NkBM2dd_qb6oclxZSu28pu-ho9boJcyifN9CtbtVXo2JiBdUu7msTTFTZeM3RlXxZzdxSFm00)

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

События не разделены на блоки, их нужно прописывать сразу. Если мы захотим, например, для каждого события прописать изменения ресурсов, то это потребует больших изменений и будет выглядеть запутанно. При работе с библиотекой nlohmann/json такое разделение событий на блоки оказалось удобнее. Мы решили остановиться все-таки на Object diagram
