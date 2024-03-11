<?php
    // Get the JSON payload from the incoming POST request
    $data = file_get_contents('php://input');

    // Decode the JSON data to an associative array
    $decodedData = json_decode($data, true);

    // Check if the 'uplink_message' and 'frm_payload' fields exist
    if (isset($decodedData['uplink_message']['frm_payload'])) {
        // Decode the 'frm_payload' field from base64
        $decodedPayload = base64_decode($decodedData['uplink_message']['frm_payload']);

        // Add the decoded payload to the array
        $decodedData['uplink_message']['decoded_frm_payload'] = $decodedPayload;
    }

    // Convert the associative array back to pretty-printed JSON
    $prettyJson = json_encode($decodedData, JSON_PRETTY_PRINT);

    // Define the name of the text file
    $filename = 'data.txt';

    // Write the pretty-printed JSON data to the text file
    file_put_contents($filename, $prettyJson);

    // Send a response back to the webhook
    echo 'OK';
?>
