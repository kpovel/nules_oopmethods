open Printf

let keep_running = ref true

(* Signal handler for Ctrl+C *)
let handle_signal _ = keep_running := false

(* Function to write lines to a file *)
let write_to_file filename ~append =
  let out_channel =
    if append
    then open_out_gen [ Open_creat; Open_text; Open_append ] 0o640 filename
    else open_out filename
  in
  let rec read_and_write () =
    if !keep_running
    then (
      try
        let line = input_line stdin in
        output_string out_channel (line ^ "\n");
        flush out_channel;
        read_and_write ()
      with
      | End_of_file -> ())
  in
  read_and_write ();
  close_out out_channel
;;

(* Main function *)
let () =
  Sys.set_signal Sys.sigint (Sys.Signal_handle handle_signal);
  try write_to_file ~append:false "output.txt" with
  | Sys_error err ->
    eprintf "Error: %s\n" err;
    exit 1
;;
