mod ffi {
    use std::slice;

    #[no_mangle]
    pub extern "C" fn ffi_mutate_my_packet(slice: *mut u8, len: usize) {
        let mut slice = unsafe { slice::from_raw_parts_mut(slice, len) };
        super::mutate_my_packet(&mut slice);
    }
}

fn mutate_my_packet(slice: &mut [u8]) {
    let message = "RewriteInRust";
    slice[..message.len()].copy_from_slice(message.as_bytes());
}
