object FormListadoJefesDpto: TFormListadoJefesDpto
  Left = 239
  Top = 148
  BorderStyle = bsSingle
  Caption = 'Ausentismo por Departamentos'
  ClientHeight = 449
  ClientWidth = 552
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
  object Bevel1: TBevel
    Left = 6
    Top = 6
    Width = 541
    Height = 408
  end
  object Panel1: TPanel
    Left = 12
    Top = 12
    Width = 529
    Height = 48
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object Label1: TLabel
      Left = 15
      Top = 16
      Width = 172
      Height = 13
      Caption = 'Cantidad de cargos que desea listar:'
    end
    object Button1: TButton
      Left = 415
      Top = 12
      Width = 94
      Height = 25
      Caption = 'Mostrar Todos'
      TabOrder = 0
      OnClick = Button1Click
    end
  end
  object ListView1: TListView
    Left = 12
    Top = 64
    Width = 529
    Height = 343
    Columns = <
      item
        Caption = 'Jefe de Departamento'
        Width = 125
      end
      item
        Caption = 'Departamento'
        Width = 100
      end
      item
        Caption = 'Trabajadores'
        Width = 100
      end
      item
        Caption = 'Hrs de Ausencias'
        Width = 100
      end
      item
        Caption = '% Ausentismo'
        Width = 100
      end>
    GridLines = True
    ReadOnly = True
    RowSelect = True
    TabOrder = 1
    ViewStyle = vsReport
  end
  object btnCerrar: TButton
    Left = 239
    Top = 419
    Width = 75
    Height = 25
    Caption = 'Cerrar'
    TabOrder = 2
    OnClick = btnCerrarClick
  end
  object CSpinEdit1: TCSpinEdit
    Left = 212
    Top = 22
    Width = 113
    Height = 22
    MaxValue = 999999
    TabOrder = 3
    OnChange = CSpinEdit1Change
  end
end
