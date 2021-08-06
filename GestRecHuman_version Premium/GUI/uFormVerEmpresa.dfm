object FormVerEmpresa: TFormVerEmpresa
  Left = 197
  Top = 168
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Datos de la Empresa'
  ClientHeight = 225
  ClientWidth = 320
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 5
    Top = 5
    Width = 309
    Height = 186
    Alignment = taRightJustify
    TabOrder = 0
    object StaticText1: TStaticText
      Left = 9
      Top = 10
      Width = 140
      Height = 17
      Alignment = taRightJustify
      AutoSize = False
      BorderStyle = sbsSunken
      Caption = 'Nombre de la Empresa:'
      TabOrder = 0
    end
    object StaticText4: TStaticText
      Left = 9
      Top = 56
      Width = 140
      Height = 17
      Alignment = taRightJustify
      AutoSize = False
      BorderStyle = sbsSunken
      Caption = 'Cantidad de Trabajadores:'
      TabOrder = 1
    end
    object StaticText5: TStaticText
      Left = 9
      Top = 81
      Width = 140
      Height = 17
      Alignment = taRightJustify
      AutoSize = False
      BorderStyle = sbsSunken
      Caption = 'Cantidad de Departamentos:'
      TabOrder = 2
    end
    object StaticText2: TStaticText
      Left = 9
      Top = 105
      Width = 140
      Height = 17
      Alignment = taRightJustify
      AutoSize = False
      BorderStyle = sbsSunken
      Caption = 'Estado Actual de la Plantilla:'
      TabOrder = 3
    end
    object StaticText3: TStaticText
      Left = 9
      Top = 33
      Width = 140
      Height = 17
      Alignment = taRightJustify
      AutoSize = False
      BorderStyle = sbsSunken
      Caption = 'Cantidad de Cargos:'
      TabOrder = 4
    end
    object StaticText6: TStaticText
      Left = 9
      Top = 131
      Width = 140
      Height = 17
      Alignment = taRightJustify
      AutoSize = False
      BorderStyle = sbsSunken
      Caption = 'Salario Aprobado:'
      TabOrder = 5
    end
    object StaticText7: TStaticText
      Left = 9
      Top = 158
      Width = 140
      Height = 17
      Alignment = taRightJustify
      AutoSize = False
      BorderStyle = sbsSunken
      Caption = 'Salario Real:'
      TabOrder = 6
    end
    object StaticText8: TStaticText
      Left = 158
      Top = 10
      Width = 140
      Height = 17
      Alignment = taRightJustify
      AutoSize = False
      BorderStyle = sbsSunken
      TabOrder = 7
    end
    object StaticText9: TStaticText
      Left = 158
      Top = 56
      Width = 140
      Height = 17
      Alignment = taRightJustify
      AutoSize = False
      BorderStyle = sbsSunken
      TabOrder = 8
    end
    object StaticText10: TStaticText
      Left = 158
      Top = 81
      Width = 140
      Height = 17
      Alignment = taRightJustify
      AutoSize = False
      BorderStyle = sbsSunken
      TabOrder = 9
    end
    object StaticText11: TStaticText
      Left = 158
      Top = 33
      Width = 140
      Height = 17
      Alignment = taRightJustify
      AutoSize = False
      BorderStyle = sbsSunken
      TabOrder = 10
    end
    object StaticText12: TStaticText
      Left = 158
      Top = 105
      Width = 140
      Height = 17
      Alignment = taRightJustify
      AutoSize = False
      BorderStyle = sbsSunken
      TabOrder = 11
    end
    object StaticText13: TStaticText
      Left = 158
      Top = 131
      Width = 140
      Height = 17
      Alignment = taRightJustify
      AutoSize = False
      BorderStyle = sbsSunken
      TabOrder = 12
    end
    object StaticText14: TStaticText
      Left = 158
      Top = 158
      Width = 140
      Height = 17
      Alignment = taRightJustify
      AutoSize = False
      BorderStyle = sbsSunken
      TabOrder = 13
    end
  end
  object btn: TButton
    Left = 122
    Top = 196
    Width = 75
    Height = 25
    Caption = 'Cerrar'
    TabOrder = 1
    OnClick = btnClick
  end
end
