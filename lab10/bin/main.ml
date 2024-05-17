open Base

let () =
  Stdio.printf "v1 = ";
  let v1 = [ 0; 0; 0 ] in
  List.iter v1 ~f:(fun x -> Stdio.printf "%d " x);
  Stdio.printf "\nv2 = ";
  let v2 = [ 2; 2; 2; 2; 2 ] in
  List.iter v2 ~f:(fun x -> Stdio.printf "%d " x);
  Stdio.printf "\nv3 = ";
  let v3 = [ 1; 1; 1 ] in
  List.iter v3 ~f:(fun x -> Stdio.printf "%d " x);
  Stdio.printf "\nv4 = ";
  let v4 = [ 2; 2; 2; 2; 2 ] in
  List.iter v4 ~f:(fun x -> Stdio.printf "%d " x);
  Stdio.printf "\nv5 = ";
  let v5 = [ 2; 2 ] in
  List.iter v5 ~f:(fun x -> Stdio.printf "%d " x);
  Stdio.printf "\n";
  ()
;;
