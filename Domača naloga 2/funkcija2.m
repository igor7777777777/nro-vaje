(* ::Package:: *)

funkcija[SteviloTock_] := Module[{znotrajKroznice = {}, znotrajKvadrata = {}},
  For[i = 1, i <= SteviloTock, i++,
    x = 2*RandomReal[] - 1;
    y = 2*RandomReal[] - 1;
    If[x^2 + y^2 < 1,
      AppendTo[znotrajKroznice, {x, y}],
      AppendTo[znotrajKvadrata, {x, y}]]];
      {znotrajKroznice, znotrajKvadrata}]


(* ::Input:: *)
(**)
