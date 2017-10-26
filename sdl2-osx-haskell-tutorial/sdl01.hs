{-# LANGUAGE OverloadedStrings #-}

import SDL.Event
import SDL.Init
import SDL.Input.Keyboard
import SDL.Video


-- This simple ADT (abstract data type) is used to hold our
-- application state: a down counter and
data AppState = AppState
    { quitCount   :: Int
    , appRunning  :: Bool
    } deriving (Show)


-- Initialise SDL, create a window, initialise the application
-- state and then loop until the termination event.
main = do
    initializeAll
    createWindow "SDL2 with Haskell" defaultWindow
    let state = AppState 3 True
    runLoop state
    quit


-- Application run loop: we spin around and around until either an
-- SDL_QUIT event or the ESC is pressed N times as set in main.
runLoop :: AppState -> IO ()
runLoop s = do
    e <- pollEvent
    case e of
        Just ev -> do
            s' <- handleEvent s (eventPayload ev)
            case (appRunning s') of
                True -> runLoop s'
                False -> return ()
        Nothing ->
                runLoop s


-- handleEvent: takes in the application state and the payload from
-- and SDL_Event and then hands back a (possibly) modified state which
-- might cause the application to terminate on the next pass.
handleEvent :: AppState -> EventPayload -> IO AppState
handleEvent s e = do
    case e of
        QuitEvent ->
            return (stopApp s)

        KeyboardEvent kbData ->
            handleKeyboard s kbData

        _ ->
            return s


-- KEYBOARD HANDLING --
-- Here we check for the ESC key being pressed. If it is we down count
-- and set the appRunning flag to False when we reach 1.
handleKeyboard :: AppState -> KeyboardEventData -> IO AppState
handleKeyboard s (KeyboardEventData _ Released _ (Keysym _ KeycodeEscape _)) = do
    case (quitCount s) of
        1 ->
            return (stopApp s)
        n ->
            return (s { quitCount = (quitCount s)-1 })


-- The catch-all keyboard handler: if no other specialisation before this
-- process the key this will return the same application state as passed in
-- to ensure the run loop continues too execute.
handleKeyboard s e = do
    return s


-- Answers a new application state with the stop condition set.
stopApp :: AppState -> AppState
stopApp s = s { appRunning = False }


